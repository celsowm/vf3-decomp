#include "sys/maple_hle.h"
#include <stdio.h>
#include <string.h>

#define BASE 0x0c000000u
static uint8_t ram[4096];
static unsigned checks, failures;
#define CHECK(x) do { ++checks; if (!(x)) { ++failures; fprintf(stderr, "line %u: %s\n", (unsigned)__LINE__, #x); } } while (0)
static void put(unsigned off, uint32_t v)
{
    for (unsigned n = 0; n < 4; ++n) ram[off+n] = (uint8_t)(v >> (8*n));
}
static uint32_t get(unsigned off)
{
    return (uint32_t)ram[off] | (uint32_t)ram[off+1]<<8 | (uint32_t)ram[off+2]<<16 | (uint32_t)ram[off+3]<<24;
}
static void request(unsigned off, unsigned port, unsigned command, unsigned recv, int last)
{
    const unsigned payload = command == 9 ? 1 : 0;
    put(off, (last ? 0x80000000u : 0u) | (port << 16) | payload);
    put(off+4, BASE+recv);
    put(off+8, command | (((port<<6) | 0x20u)<<8) | ((port<<6)<<16) | (payload<<24));
    if (payload) put(off+12, 0x01000000u);
}
static vf3_maple_dma_result run(vf3_maple_bus *bus)
{
    return vf3_maple_dma_bus(ram, BASE, sizeof ram, BASE, bus);
}
int main(void)
{
    vf3_maple_bus bus;
    vf3_maple_dma_result r;
    vf3_maple_bus_init(&bus, 3);
    CHECK(bus.connected == 3 && bus.pads[0].buttons == 0xffff && bus.pads[3].joyx == 128);
    bus.pads[0] = (vf3_maple_pad){0xfffbu, 2, 3, 4, 5, 6, 7};
    bus.pads[1] = (vf3_maple_pad){0xfffdu, 12, 13, 14, 15, 16, 17};
    request(0, 0, 9, 1024, 0);
    request(16, 1, 9, 1040, 1);
    r = run(&bus);
    CHECK(r.status == VF3_MAPLE_DMA_OK && r.blocks == 2);
    CHECK(get(1024) == 0x03200008u && get(1040) == 0x03604008u);
    CHECK(get(1028) == 0x01000000u && get(1044) == 0x01000000u);
    CHECK(get(1032) == 0x0302fffbu && get(1048) == 0x0d0cfffdu);
    CHECK(get(1036) == 0x07060504u && get(1052) == 0x11100f0eu);
    bus.connected = 2; /* P1 unplugged; P2 stays in port B. */
    r = run(&bus);
    CHECK(r.status == VF3_MAPLE_DMA_OK && get(1024) == 0xffffffffu);
    CHECK(get(1040) == 0x03604008u && get(1048) == 0x0d0cfffdu);
    bus.connected = 15;
    for (unsigned p = 0; p < VF3_MAPLE_PORTS; ++p) {
        request(0, p, 1, 1024, 1);
        r = run(&bus);
        CHECK(r.status == VF3_MAPLE_DMA_OK && r.blocks == 1);
        CHECK(get(1024) == (0x1c200005u | (p<<22) | (p<<14)));
        CHECK(get(1028) == 0x01000000u && get(1032) == 0xfe060f00u);
        CHECK(!memcmp(ram+1046, "Dreamcast Controller", 20));
        CHECK(ram[1136] == 0xae && ram[1139] == 1);
    }
    request(0, 1, 9, 1024, 1);
    put(8, get(8) & ~0x4000u); /* port A destination in a port B DMA */
    CHECK(run(&bus).status == VF3_MAPLE_DMA_OK && get(1024) == 0xffffffffu);
    request(0, 0, 9, 1024, 1);
    put(8, (get(8) & ~0x3f00u) | 0x0100u); /* no VMU/sub-unit */
    CHECK(run(&bus).status == VF3_MAPLE_DMA_OK && get(1024) == 0xffffffffu);
    request(0, 0, 9, 1024, 1);
    CHECK(vf3_maple_dma_bus(ram, 0x8c000000u, sizeof ram, 0xac000000u, &bus).status == VF3_MAPLE_DMA_OK);
    memset(ram+4092, 0xa5, 4);
    put(4, BASE+4092);
    r = run(&bus);
    CHECK(r.status == VF3_MAPLE_DMA_BAD_RECEIVE && r.blocks == 0 && r.address == BASE+4092);
    CHECK(get(4092) == 0xa5a5a5a5u); /* no partially-written response */
    request(0, 0, 9, 1024, 1);
    put(0, get(0) | 0x100u);
    CHECK(run(&bus).status == VF3_MAPLE_DMA_UNSUPPORTED_PATTERN);
    request(0, 0, 9, 1024, 1);
    put(8, get(8) & 0x00ffffffu); /* descriptor/frame length disagree */
    CHECK(run(&bus).status == VF3_MAPLE_DMA_BAD_LIST);
    CHECK(vf3_maple_dma_bus(ram, BASE, 11, BASE, &bus).status == VF3_MAPLE_DMA_BAD_LIST);
    CHECK(vf3_maple_dma_bus(ram, BASE, sizeof ram, BASE+1, &bus).status == VF3_MAPLE_DMA_BAD_LIST);
    CHECK(vf3_maple_dma_bus(NULL, BASE, sizeof ram, BASE, &bus).status == VF3_MAPLE_DMA_BAD_LIST);
    for (unsigned n = 0; n < 64; ++n) request(12*n, 0, 1, 2048, 0);
    r = run(&bus);
    CHECK(r.status == VF3_MAPLE_DMA_BLOCK_LIMIT && r.blocks == 64);
    request(0, 0, 9, 1024, 1);
    CHECK(vf3_maple_dma(ram, BASE, sizeof ram, BASE, &bus.pads[0]) == 1);
    CHECK(get(1032) == 0x0302fffbu);
    CHECK(vf3_maple_dma(ram, BASE, sizeof ram, BASE, NULL) == 1 && get(1024) == 0xffffffffu);
    printf("Maple bus: %u checks, %u failures\n", checks, failures);
    return failures ? 1 : 0;
}
