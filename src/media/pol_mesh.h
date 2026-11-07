/* Naomi-style mesh records embedded in VF3tb POL packages.
 * The reader is clean-room C and owns no input bytes. */
#ifndef VF3_POL_MESH_H
#define VF3_POL_MESH_H

#include <stdint.h>

/* A mesh may explicitly have no texture. The all-ones value is distinct from
 * every valid descriptor index and is passed through to the native renderer. */
#define POL_TEXTURE_NONE UINT32_MAX

typedef struct {
    float x, y, z;
    float nx, ny, nz;
    float u, v;
} PolMeshVertex;

typedef struct {
    uint32_t slot_index;
    uint32_t texture_index;
    uint32_t first_index;
    uint32_t index_count;
    uint32_t flags;
    float center[3];
    float radius;
    float color[3];
} PolMesh;

/* One tagged POL slot payload. Keep this boundary after decoding: fighter
 * packages contain several independently indexed model payloads, and flattening
 * them loses the IDs needed by native part selection and pose application. */
typedef struct {
    uint32_t slot_index;
    uint32_t file_start;
    uint32_t file_end;
    uint32_t first_mesh;
    uint32_t mesh_count;
} PolModel;

typedef struct {
    PolMeshVertex *vertices;
    uint32_t vertex_count;
    uint32_t *indices;
    uint32_t index_count;
    PolMesh *meshes;
    uint32_t mesh_count;
    PolModel *models;
    uint32_t model_count;
} PolScene;

/* Parse every tagged model in a POL package. Vertices are shared by their
 * backward-reference records; indices describe triangle lists and strips.
 * Returns 0 on success, -1 for bad arguments, -2 for malformed data, -3 for
 * allocation failure, and -4 for an unresolved backward vertex reference. */
int pol_scene_parse(const void *data, uint32_t size, PolScene *out);
void pol_scene_free(PolScene *scene);

#endif
