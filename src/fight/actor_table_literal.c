/* Registration lists reached by literal JSR resource callbacks. The lists
 * describe commands and object fields; this code does not interpret opcodes. */
#include "fight/matrix_family.h"

typedef struct {
    uint16_t command, field_offset;
    int16_t index_value;
    uint32_t return_pc;
} literal_binding;

static const literal_binding list_8c0a4664[] = {
    {0x58f, 0, -1, 0xc0a4672u},
    {0x590, 64, 64, 0xc0a467cu},
    {0x5ba, 4, -1, 0xc0a4684u},
    {0x5bb, 8, -1, 0xc0a468cu},
    {0x5bc, 60, -1, 0xc0a4694u},
    {0x5bd, 36, -1, 0xc0a469cu},
    {0x5be, 40, -1, 0xc0a46a4u},
    {0x5bf, 44, -1, 0xc0a46acu},
    {0x5c0, 48, -1, 0xc0a46b4u},
    {0x5c1, 52, -1, 0xc0a46bcu},
    {0x5c2, 32, -1, 0xc0a46c4u},
    {0x5c3, 12, -1, 0xc0a46ccu},
    {0x5c4, 16, -1, 0xc0a46d4u},
    {0x5c5, 20, -1, 0xc0a46dcu},
    {0x5c6, 24, -1, 0xc0a46e4u},
    {0x5c7, 28, -1, 0xc0a46ecu},
    {0x5c8, 56, -1, 0xc0a46f4u},
    {0x59c, 68, 68, 0xc0a46feu},
    {0x59d, 72, 72, 0xc0a4708u},
    {0x59e, 76, 76, 0xc0a4712u},
    {0x59f, 80, 80, 0xc0a471cu},
    {0x5a1, 84, 84, 0xc0a4726u},
    {0x5a2, 88, 88, 0xc0a4730u},
    {0x5a3, 92, 92, 0xc0a473au},
    {0x5a6, 96, 96, 0xc0a4744u},
    {0x5a7, 100, 100, 0xc0a474eu},
    {0x5a8, 104, 104, 0xc0a4758u},
    {0x5b4, 108, 108, 0xc0a4762u},
    {0x5b5, 112, 112, 0xc0a476cu},
    {0x5b7, 116, 116, 0xc0a4776u},
    {0x5b8, 120, 120, 0xc0a4780u},
    {0x5d4, 124, -1, 0x0u},
};

static const literal_binding list_8c0a4d3c[] = {
    {0x7a5, 0, -1, 0xc0a4d4au},
    {0x7a6, 64, 64, 0xc0a4d54u},
    {0x7b8, 4, -1, 0xc0a4d5cu},
    {0x7b9, 8, -1, 0xc0a4d64u},
    {0x7ba, 60, -1, 0xc0a4d6cu},
    {0x7bb, 36, -1, 0xc0a4d74u},
    {0x7bc, 40, -1, 0xc0a4d7cu},
    {0x7bd, 44, -1, 0xc0a4d84u},
    {0x7be, 48, -1, 0xc0a4d8cu},
    {0x7bf, 52, -1, 0xc0a4d94u},
    {0x7c0, 32, -1, 0xc0a4d9cu},
    {0x7c1, 12, -1, 0xc0a4da4u},
    {0x7c2, 16, -1, 0xc0a4dacu},
    {0x7c3, 20, -1, 0xc0a4db4u},
    {0x7c4, 24, -1, 0xc0a4dbcu},
    {0x7c5, 28, -1, 0xc0a4dc4u},
    {0x7c6, 56, -1, 0xc0a4dccu},
    {0x7b4, 68, 68, 0xc0a4dd6u},
    {0x7b5, 72, 72, 0xc0a4de0u},
    {0x7b6, 76, 76, 0xc0a4deau},
    {0x7a2, 80, 80, 0xc0a4df4u},
    {0x7a3, 84, 84, 0xc0a4dfeu},
    {0x7a4, 88, 88, 0xc0a4e08u},
    {0x7a8, 92, -1, 0x0u},
};

static const literal_binding list_8c0a5758[] = {
    {0xa16, 0, -1, 0xc0a5766u},
    {0xa17, 64, 64, 0xc0a5770u},
    {0xa71, 4, -1, 0xc0a5778u},
    {0xa72, 8, -1, 0xc0a5780u},
    {0xa73, 60, -1, 0xc0a5788u},
    {0xa74, 36, -1, 0xc0a5790u},
    {0xa75, 40, -1, 0xc0a5798u},
    {0xa76, 44, -1, 0xc0a57a0u},
    {0xa77, 48, -1, 0xc0a57a8u},
    {0xa78, 52, -1, 0xc0a57b0u},
    {0xa79, 32, -1, 0xc0a57b8u},
    {0xa7a, 12, -1, 0xc0a57c0u},
    {0xa7b, 16, -1, 0xc0a57c8u},
    {0xa7c, 20, -1, 0xc0a57d0u},
    {0xa7d, 24, -1, 0xc0a57d8u},
    {0xa7e, 28, -1, 0xc0a57e0u},
    {0xa7f, 56, -1, 0xc0a57e8u},
    {0xa2a, 68, 68, 0xc0a57f2u},
    {0xa2b, 72, 72, 0xc0a57fcu},
    {0xa2c, 76, 76, 0xc0a5806u},
    {0xa2d, 80, 80, 0xc0a5810u},
    {0xa2e, 84, 84, 0xc0a581au},
    {0xa2f, 88, 88, 0xc0a5824u},
    {0xa30, 92, 92, 0xc0a582eu},
    {0xa31, 96, 96, 0xc0a5838u},
    {0xa32, 100, 100, 0xc0a5842u},
    {0xa33, 104, 104, 0xc0a584cu},
    {0xa34, 108, 108, 0xc0a5856u},
    {0xa35, 112, 112, 0xc0a5860u},
    {0xa36, 116, 116, 0xc0a586au},
    {0xa37, 120, 120, 0xc0a5874u},
    {0xa38, 124, 124, 0xc0a587eu},
    {0xa39, 128, 128, 0xc0a5888u},
    {0xa3a, 132, 132, 0xc0a5892u},
    {0xa3b, 136, 136, 0xc0a589cu},
    {0xa3c, 140, 140, 0xc0a58a6u},
    {0xa3d, 144, 144, 0xc0a58b0u},
    {0xa3e, 148, 148, 0xc0a58bau},
    {0xa3f, 152, 152, 0xc0a58c4u},
    {0xa40, 156, 156, 0xc0a5932u},
    {0xa41, 160, 160, 0xc0a593cu},
    {0xa42, 164, 164, 0xc0a5946u},
    {0xa43, 168, 168, 0xc0a5950u},
    {0xa44, 172, 172, 0xc0a595au},
    {0xa45, 176, 176, 0xc0a5964u},
    {0xa5f, 180, 180, 0xc0a596eu},
    {0xa60, 184, 184, 0xc0a5978u},
    {0xa61, 188, 188, 0xc0a5982u},
    {0xa62, 192, 192, 0xc0a598cu},
    {0xa64, 196, 196, 0xc0a5996u},
    {0xa65, 200, 200, 0xc0a59a0u},
    {0xa67, 204, 204, 0xc0a59aau},
    {0xa68, 208, 208, 0xc0a59b4u},
    {0xa69, 212, 212, 0xc0a59beu},
    {0xa6a, 216, 216, 0xc0a59c8u},
    {0xa6b, 220, 220, 0xc0a59d2u},
    {0xa6c, 224, 224, 0xc0a59dcu},
    {0xa15, 228, 228, 0x0u},
};

static const literal_binding list_8c0a5b50[] = {
    {0xc2f, 0, -1, 0xc0a5b5eu},
    {0xc30, 64, 64, 0xc0a5b68u},
    {0xc56, 4, -1, 0xc0a5b70u},
    {0xc57, 8, -1, 0xc0a5b78u},
    {0xc58, 60, -1, 0xc0a5b80u},
    {0xc59, 36, -1, 0xc0a5b88u},
    {0xc5a, 40, -1, 0xc0a5b90u},
    {0xc5b, 44, -1, 0xc0a5b98u},
    {0xc5c, 48, -1, 0xc0a5ba0u},
    {0xc5d, 52, -1, 0xc0a5ba8u},
    {0xc5e, 32, -1, 0xc0a5bb0u},
    {0xc5f, 12, -1, 0xc0a5bb8u},
    {0xc61, 16, -1, 0xc0a5bc0u},
    {0xc62, 20, -1, 0xc0a5bc8u},
    {0xc63, 24, -1, 0xc0a5bd0u},
    {0xc64, 28, -1, 0xc0a5bd8u},
    {0xc60, 56, -1, 0xc0a5be0u},
    {0xc45, 68, 68, 0xc0a5beau},
    {0xc46, 72, 72, 0xc0a5bf4u},
    {0xc47, 76, 76, 0xc0a5bfeu},
    {0xc4a, 80, 80, 0xc0a5c08u},
    {0xc4b, 84, 84, 0xc0a5c12u},
    {0xc4d, 88, 88, 0xc0a5c1cu},
    {0xc50, 92, 92, 0xc0a5c26u},
    {0xc51, 96, 96, 0xc0a5c30u},
    {0xc53, 100, 100, 0xc0a5c3au},
    {0xc2d, 104, -1, 0xc0a5c46u},
};

static const literal_binding list_8c0a5d98[] = {
    {0xb97, 0, -1, 0xc0a5da6u},
    {0xb98, 64, 64, 0xc0a5db0u},
    {0xbbe, 4, -1, 0xc0a5db8u},
    {0xbbf, 8, -1, 0xc0a5dc0u},
    {0xbc0, 60, -1, 0xc0a5dc8u},
    {0xbc1, 36, -1, 0xc0a5dd0u},
    {0xbc2, 40, -1, 0xc0a5dd8u},
    {0xbc3, 44, -1, 0xc0a5de0u},
    {0xbc4, 48, -1, 0xc0a5de8u},
    {0xbc5, 52, -1, 0xc0a5df0u},
    {0xbc6, 32, -1, 0xc0a5df8u},
    {0xbc7, 12, -1, 0xc0a5e00u},
    {0xbc9, 16, -1, 0xc0a5e08u},
    {0xbca, 20, -1, 0xc0a5e10u},
    {0xbcb, 24, -1, 0xc0a5e18u},
    {0xbcc, 28, -1, 0xc0a5e20u},
    {0xbc8, 56, -1, 0xc0a5e28u},
    {0xbae, 68, 68, 0xc0a5e32u},
    {0xbaf, 72, 72, 0xc0a5e3cu},
    {0xbb0, 76, 76, 0xc0a5e46u},
    {0xbb3, 80, 80, 0xc0a5e50u},
    {0xbb4, 84, 84, 0xc0a5e5au},
    {0xbb6, 88, 88, 0xc0a5e64u},
    {0xbb9, 92, 92, 0xc0a5e6eu},
    {0xbba, 96, 96, 0xc0a5e78u},
    {0xbbc, 100, -1, 0xc0a5e84u},
};

static const literal_binding list_8c0a3e1e[] = {
    {0x35e, 0, -1, 0xc0a3e2cu},
    {0x35f, 64, 64, 0xc0a3e36u},
    {0x38b, 4, -1, 0xc0a3e3eu},
    {0x38c, 8, -1, 0xc0a3e46u},
    {0x38d, 60, -1, 0xc0a3e4eu},
    {0x38e, 36, -1, 0xc0a3e56u},
    {0x38f, 40, -1, 0xc0a3e5eu},
    {0x390, 44, -1, 0xc0a3e66u},
    {0x391, 48, -1, 0xc0a3e6eu},
    {0x392, 52, -1, 0xc0a3e76u},
    {0x393, 32, -1, 0xc0a3e7eu},
    {0x394, 12, -1, 0xc0a3e86u},
    {0x395, 16, -1, 0xc0a3e8eu},
    {0x396, 20, -1, 0xc0a3e96u},
    {0x397, 24, -1, 0xc0a3e9eu},
    {0x398, 28, -1, 0xc0a3ea6u},
    {0x399, 56, -1, 0xc0a3eaeu},
    {0x36b, 68, 68, 0xc0a3eb8u},
    {0x377, 72, 72, 0xc0a3ec2u},
    {0x36c, 76, 76, 0xc0a3eccu},
    {0x382, 80, 80, 0xc0a3ed6u},
    {0x384, 84, 84, 0xc0a3ee0u},
    {0x36e, 88, 88, 0xc0a3eeau},
    {0x36f, 92, 92, 0xc0a3ef4u},
    {0x370, 96, 96, 0xc0a3efeu},
    {0x371, 100, 100, 0xc0a3f08u},
    {0x372, 104, 104, 0xc0a3f12u},
    {0x373, 108, 108, 0xc0a3f1cu},
    {0x374, 112, 112, 0xc0a3f26u},
    {0x375, 116, 116, 0xc0a3f30u},
    {0x376, 120, 120, 0xc0a3f3au},
    {0x378, 124, 124, 0xc0a3f44u},
    {0x379, 128, 128, 0xc0a3f4eu},
    {0x37a, 132, 132, 0xc0a3f58u},
    {0x37b, 136, 136, 0xc0a3f62u},
    {0x37c, 140, 140, 0xc0a3f6cu},
    {0x37d, 144, 144, 0xc0a3f76u},
    {0x37e, 148, 148, 0xc0a3f80u},
    {0x37f, 152, 152, 0xc0a3f8au},
    {0x380, 156, 156, 0xc0a3ffau},
    {0x381, 160, 160, 0xc0a4004u},
    {0x383, 164, 164, 0x0u},
};

static const literal_binding list_8c0a52ec[] = {
    {0xadb, 0, -1, 0xc0a52fau},
    {0xadc, 64, 64, 0xc0a5304u},
    {0xb2c, 4, -1, 0xc0a530cu},
    {0xb2d, 8, -1, 0xc0a5314u},
    {0xb2e, 60, -1, 0xc0a531cu},
    {0xb2f, 36, -1, 0xc0a5324u},
    {0xb30, 40, -1, 0xc0a532cu},
    {0xb31, 44, -1, 0xc0a5334u},
    {0xb32, 48, -1, 0xc0a533cu},
    {0xb33, 52, -1, 0xc0a5344u},
    {0xb34, 32, -1, 0xc0a534cu},
    {0xb35, 12, -1, 0xc0a5354u},
    {0xb36, 16, -1, 0xc0a535cu},
    {0xb37, 20, -1, 0xc0a5364u},
    {0xb38, 24, -1, 0xc0a536cu},
    {0xb39, 28, -1, 0xc0a5374u},
    {0xb3a, 56, -1, 0xc0a537cu},
    {0xae9, 68, 68, 0xc0a5386u},
    {0xaed, 72, 72, 0xc0a5390u},
    {0xaef, 76, 76, 0xc0a539au},
    {0xaf0, 80, 80, 0xc0a53a4u},
    {0xaf3, 84, 84, 0xc0a53aeu},
    {0xb01, 88, 88, 0xc0a53b8u},
    {0xb02, 92, 92, 0xc0a53c2u},
    {0xb03, 96, 96, 0xc0a53ccu},
    {0xb04, 100, 100, 0xc0a53d6u},
    {0xb05, 104, 104, 0xc0a53e0u},
    {0xb06, 108, 108, 0xc0a53eau},
    {0xb07, 112, 112, 0xc0a53f4u},
    {0xb08, 116, 116, 0xc0a53feu},
    {0xb0a, 120, 120, 0xc0a5408u},
    {0xb0b, 124, 124, 0xc0a5412u},
    {0xb0d, 128, 128, 0xc0a541cu},
    {0xb0e, 132, 132, 0xc0a5426u},
    {0xb0f, 136, 136, 0xc0a5430u},
    {0xb10, 140, 140, 0xc0a543au},
    {0xb11, 144, 144, 0xc0a5444u},
    {0xb19, 148, 148, 0xc0a544eu},
    {0xb1a, 152, 152, 0xc0a5458u},
    {0xb1b, 156, 156, 0xc0a54c6u},
    {0xb1c, 160, 160, 0xc0a54d0u},
    {0xada, 164, 164, 0x0u},
};

static const literal_binding list_8c0a4410[] = {
    {0x626, 0, -1, 0xc0a441eu},
    {0x627, 64, 64, 0xc0a4428u},
    {0x638, 4, -1, 0xc0a4430u},
    {0x639, 8, -1, 0xc0a4438u},
    {0x63a, 60, -1, 0xc0a4440u},
    {0x63b, 36, -1, 0xc0a4448u},
    {0x63c, 40, -1, 0xc0a4450u},
    {0x63d, 44, -1, 0xc0a4458u},
    {0x63e, 48, -1, 0xc0a4460u},
    {0x63f, 52, -1, 0xc0a4468u},
    {0x640, 32, -1, 0xc0a4470u},
    {0x641, 12, -1, 0xc0a4478u},
    {0x642, 16, -1, 0xc0a4480u},
    {0x643, 20, -1, 0xc0a4488u},
    {0x644, 24, -1, 0xc0a4490u},
    {0x645, 28, -1, 0xc0a4498u},
    {0x646, 56, -1, 0xc0a44a0u},
    {0x629, 68, 68, 0xc0a44aau},
    {0x62a, 72, 72, 0xc0a44b4u},
    {0x62b, 76, 76, 0xc0a44beu},
    {0x62c, 80, 80, 0xc0a44c8u},
    {0x652, 84, -1, 0x0u},
};

static const literal_binding list_8c0a423a[] = {
    {0x48d, 0, -1, 0xc0a4248u},
    {0x48e, 64, 64, 0xc0a4252u},
    {0x49d, 4, -1, 0xc0a425au},
    {0x49e, 8, -1, 0xc0a4262u},
    {0x49f, 60, -1, 0xc0a426au},
    {0x4a0, 36, -1, 0xc0a4272u},
    {0x4a1, 40, -1, 0xc0a427au},
    {0x4a2, 44, -1, 0xc0a4282u},
    {0x4a3, 48, -1, 0xc0a428au},
    {0x4a4, 52, -1, 0xc0a4292u},
    {0x4a5, 32, -1, 0xc0a429au},
    {0x4a6, 12, -1, 0xc0a42a2u},
    {0x4a7, 16, -1, 0xc0a42aau},
    {0x4a8, 20, -1, 0xc0a42b2u},
    {0x4a9, 24, -1, 0xc0a42bau},
    {0x4aa, 28, -1, 0xc0a42c2u},
    {0x4ab, 56, -1, 0xc0a42cau},
    {0x49a, 68, 68, 0xc0a42d4u},
    {0x49b, 72, 72, 0xc0a42deu},
    {0x48c, 76, 76, 0xc0a42e8u},
    {0x48b, 80, -1, 0x0u},
};

static const literal_binding list_8c0a4b5e[] = {
    {0x828, 0, -1, 0xc0a4b6cu},
    {0x829, 64, 64, 0xc0a4b76u},
    {0x838, 4, -1, 0xc0a4b7eu},
    {0x839, 8, -1, 0xc0a4b86u},
    {0x83a, 60, -1, 0xc0a4b8eu},
    {0x83b, 36, -1, 0xc0a4b96u},
    {0x83c, 40, -1, 0xc0a4b9eu},
    {0x83d, 44, -1, 0xc0a4ba6u},
    {0x83e, 48, -1, 0xc0a4baeu},
    {0x83f, 52, -1, 0xc0a4bb6u},
    {0x840, 32, -1, 0xc0a4bbeu},
    {0x841, 12, -1, 0xc0a4bc6u},
    {0x842, 16, -1, 0xc0a4bceu},
    {0x843, 20, -1, 0xc0a4bd6u},
    {0x844, 24, -1, 0xc0a4bdeu},
    {0x845, 28, -1, 0xc0a4be6u},
    {0x846, 56, -1, 0xc0a4beeu},
    {0x835, 68, 68, 0xc0a4bf8u},
    {0x836, 72, 72, 0xc0a4c02u},
    {0x827, 76, -1, 0x0u},
};

static const literal_binding list_8c0a61fa[] = {
    {0xe67, 0, -1, 0xc0a6208u},
    {0xe68, 64, 64, 0xc0a6212u},
    {0xe78, 4, -1, 0xc0a621au},
    {0xe79, 8, -1, 0xc0a6222u},
    {0xe7a, 60, -1, 0xc0a622au},
    {0xe7b, 36, -1, 0xc0a6232u},
    {0xe7c, 40, -1, 0xc0a623au},
    {0xe7d, 44, -1, 0xc0a6242u},
    {0xe7e, 48, -1, 0xc0a624au},
    {0xe7f, 52, -1, 0xc0a6252u},
    {0xe80, 32, -1, 0xc0a625au},
    {0xe81, 12, -1, 0xc0a6262u},
    {0xe82, 16, -1, 0xc0a626au},
    {0xe83, 20, -1, 0xc0a6272u},
    {0xe84, 24, -1, 0xc0a627au},
    {0xe85, 28, -1, 0xc0a6282u},
    {0xe86, 56, -1, 0xc0a628au},
    {0xe74, 68, 68, 0xc0a6294u},
    {0xe75, 72, 72, 0xc0a629eu},
    {0xe76, 76, -1, 0x0u},
};

static const literal_binding list_8c0a40ac[] = {
    {0x507, 0, -1, 0xc0a40bau},
    {0x508, 64, 64, 0xc0a40c4u},
    {0x526, 4, -1, 0xc0a40ccu},
    {0x527, 8, -1, 0xc0a40d4u},
    {0x528, 60, -1, 0xc0a40dcu},
    {0x529, 36, -1, 0xc0a40e4u},
    {0x52a, 40, -1, 0xc0a40ecu},
    {0x52b, 44, -1, 0xc0a40f4u},
    {0x52c, 48, -1, 0xc0a40fcu},
    {0x52d, 52, -1, 0xc0a4104u},
    {0x52e, 32, -1, 0xc0a410cu},
    {0x52f, 12, -1, 0xc0a4114u},
    {0x530, 16, -1, 0xc0a411cu},
    {0x531, 20, -1, 0xc0a4124u},
    {0x532, 24, -1, 0xc0a412cu},
    {0x533, 28, -1, 0xc0a4134u},
    {0x534, 56, -1, 0xc0a413cu},
    {0x517, 68, 68, 0xc0a4146u},
    {0x519, 72, -1, 0x0u},
};

static const literal_binding list_8c0a486e[] = {
    {0x723, 0, -1, 0xc0a487cu},
    {0x724, 64, 64, 0xc0a4886u},
    {0x733, 4, -1, 0xc0a488eu},
    {0x734, 8, -1, 0xc0a4896u},
    {0x735, 60, -1, 0xc0a489eu},
    {0x736, 36, -1, 0xc0a48a6u},
    {0x737, 40, -1, 0xc0a48aeu},
    {0x738, 44, -1, 0xc0a48b6u},
    {0x739, 48, -1, 0xc0a48beu},
    {0x73a, 52, -1, 0xc0a48c6u},
    {0x73b, 32, -1, 0xc0a48ceu},
    {0x73c, 12, -1, 0xc0a48d6u},
    {0x73d, 16, -1, 0xc0a48deu},
    {0x73e, 20, -1, 0xc0a48e6u},
    {0x73f, 24, -1, 0xc0a48eeu},
    {0x740, 28, -1, 0xc0a48f6u},
    {0x741, 56, -1, 0xc0a48feu},
    {0x730, 68, 68, 0xc0a4908u},
    {0x731, 72, -1, 0x0u},
};

static const literal_binding list_8c0a49e2[] = {
    {0x6a9, 0, -1, 0xc0a49f0u},
    {0x6aa, 64, 64, 0xc0a49fau},
    {0x6b9, 4, -1, 0xc0a4a02u},
    {0x6ba, 8, -1, 0xc0a4a0au},
    {0x6bb, 60, -1, 0xc0a4a12u},
    {0x6bc, 36, -1, 0xc0a4a1au},
    {0x6bd, 40, -1, 0xc0a4a22u},
    {0x6be, 44, -1, 0xc0a4a2au},
    {0x6bf, 48, -1, 0xc0a4a32u},
    {0x6c0, 52, -1, 0xc0a4a3au},
    {0x6c1, 32, -1, 0xc0a4a42u},
    {0x6c2, 12, -1, 0xc0a4a4au},
    {0x6c3, 16, -1, 0xc0a4a52u},
    {0x6c4, 20, -1, 0xc0a4a5au},
    {0x6c5, 24, -1, 0xc0a4a62u},
    {0x6c6, 28, -1, 0xc0a4a6au},
    {0x6c7, 56, -1, 0xc0a4a72u},
    {0x6b6, 68, 68, 0xc0a4a7cu},
    {0x6b7, 72, -1, 0x0u},
};

static const literal_binding list_8c0a4efc[] = {
    {0x998, 0, -1, 0xc0a4f0au},
    {0x999, 64, 64, 0xc0a4f14u},
    {0x9ac, 4, -1, 0xc0a4f1cu},
    {0x9ad, 8, -1, 0xc0a4f24u},
    {0x9ae, 60, -1, 0xc0a4f2cu},
    {0x9af, 36, -1, 0xc0a4f34u},
    {0x9b0, 40, -1, 0xc0a4f3cu},
    {0x9b1, 44, -1, 0xc0a4f44u},
    {0x9b2, 48, -1, 0xc0a4f4cu},
    {0x9b3, 52, -1, 0xc0a4f54u},
    {0x9b4, 32, -1, 0xc0a4f5cu},
    {0x9b5, 12, -1, 0xc0a4f64u},
    {0x9b6, 16, -1, 0xc0a4f6cu},
    {0x9b7, 20, -1, 0xc0a4f74u},
    {0x9b8, 24, -1, 0xc0a4f7cu},
    {0x9b9, 28, -1, 0xc0a4f84u},
    {0x9ba, 56, -1, 0x0u},
};

static const literal_binding list_8c0a5068[] = {
    {0x8ac, 0, -1, 0xc0a5076u},
    {0x8ad, 64, 64, 0xc0a5080u},
    {0x8ba, 4, -1, 0xc0a5088u},
    {0x8bb, 8, -1, 0xc0a5090u},
    {0x8bc, 60, -1, 0xc0a5098u},
    {0x8bd, 36, -1, 0xc0a50a0u},
    {0x8be, 40, -1, 0xc0a50a8u},
    {0x8bf, 44, -1, 0xc0a50b0u},
    {0x8c0, 48, -1, 0xc0a50b8u},
    {0x8c1, 52, -1, 0xc0a50c0u},
    {0x8c2, 32, -1, 0xc0a50c8u},
    {0x8c3, 12, -1, 0xc0a50d0u},
    {0x8c4, 16, -1, 0xc0a50d8u},
    {0x8c5, 20, -1, 0xc0a50e0u},
    {0x8c6, 24, -1, 0xc0a50e8u},
    {0x8c7, 28, -1, 0xc0a50f0u},
    {0x8c8, 56, -1, 0x0u},
};

static const literal_binding list_8c0a5f52[] = {
    {0xd52, 0, -1, 0xc0a5f60u},
    {0xd53, 64, 64, 0xc0a5f6au},
    {0xd60, 4, -1, 0xc0a5f72u},
    {0xd61, 8, -1, 0xc0a5f7au},
    {0xd62, 60, -1, 0xc0a5f82u},
    {0xd63, 36, -1, 0xc0a5f8au},
    {0xd64, 40, -1, 0xc0a5f92u},
    {0xd65, 44, -1, 0xc0a5f9au},
    {0xd66, 48, -1, 0xc0a5fa2u},
    {0xd67, 52, -1, 0xc0a5faau},
    {0xd68, 32, -1, 0xc0a5fb2u},
    {0xd69, 12, -1, 0xc0a5fbau},
    {0xd6a, 16, -1, 0xc0a5fc2u},
    {0xd6b, 20, -1, 0xc0a5fcau},
    {0xd6c, 24, -1, 0xc0a5fd2u},
    {0xd6d, 28, -1, 0xc0a5fdau},
    {0xd6e, 56, -1, 0x0u},
};

static const literal_binding list_8c0a609a[] = {
    {0xcdb, 0, -1, 0xc0a60a8u},
    {0xcdc, 64, 64, 0xc0a60b2u},
    {0xcea, 4, -1, 0xc0a60bau},
    {0xceb, 8, -1, 0xc0a60c2u},
    {0xcec, 60, -1, 0xc0a60cau},
    {0xced, 36, -1, 0xc0a60d2u},
    {0xcee, 40, -1, 0xc0a60dau},
    {0xcef, 44, -1, 0xc0a60e2u},
    {0xcf0, 48, -1, 0xc0a60eau},
    {0xcf1, 52, -1, 0xc0a60f2u},
    {0xcf2, 32, -1, 0xc0a60fau},
    {0xcf3, 12, -1, 0xc0a6102u},
    {0xcf4, 16, -1, 0xc0a610au},
    {0xcf5, 20, -1, 0xc0a6112u},
    {0xcf6, 24, -1, 0xc0a611au},
    {0xcf7, 28, -1, 0xc0a6122u},
    {0xcf8, 56, -1, 0x0u},
};

int vf3_actor_table_literal_c(uint32_t entry, vf3_matrix_state *s,
                             const vf3_ram_map *ram)
{
    const literal_binding *list;
    unsigned count, instructions;
    uint32_t tail = 0, object;
    uint32_t *r = s->v;
    switch (entry) {
    case 0xc0a4664u:
        list = list_8c0a4664;
        count = sizeof(list_8c0a4664) / sizeof(*list);
        instructions = 150;
        break;
    case 0xc0a4d3cu:
        list = list_8c0a4d3c;
        count = sizeof(list_8c0a4d3c) / sizeof(*list);
        instructions = 110;
        break;
    case 0xc0a5758u:
        list = list_8c0a5758;
        count = sizeof(list_8c0a5758) / sizeof(*list);
        instructions = 281;
        break;
    case 0xc0a5b50u:
        list = list_8c0a5b50;
        count = sizeof(list_8c0a5b50) / sizeof(*list);
        instructions = 127;
        tail = 0x0c095178u;
        break;
    case 0xc0a5d98u:
        list = list_8c0a5d98;
        count = sizeof(list_8c0a5d98) / sizeof(*list);
        instructions = 122;
        tail = 0x0c095178u;
        break;
    case 0xc0a3e1eu:
        list = list_8c0a3e1e;
        count = sizeof(list_8c0a3e1e) / sizeof(*list);
        instructions = 201;
        break;
    case 0xc0a52ecu:
        list = list_8c0a52ec;
        count = sizeof(list_8c0a52ec) / sizeof(*list);
        instructions = 201;
        break;
    case 0xc0a4410u:
        list = list_8c0a4410;
        count = sizeof(list_8c0a4410) / sizeof(*list);
        instructions = 100;
        break;
    case 0xc0a423au:
        list = list_8c0a423a;
        count = sizeof(list_8c0a423a) / sizeof(*list);
        instructions = 95;
        break;
    case 0xc0a4b5eu:
        list = list_8c0a4b5e;
        count = sizeof(list_8c0a4b5e) / sizeof(*list);
        instructions = 90;
        break;
    case 0xc0a61fau:
        list = list_8c0a61fa;
        count = sizeof(list_8c0a61fa) / sizeof(*list);
        instructions = 90;
        break;
    case 0xc0a40acu:
        list = list_8c0a40ac;
        count = sizeof(list_8c0a40ac) / sizeof(*list);
        instructions = 85;
        break;
    case 0xc0a486eu:
        list = list_8c0a486e;
        count = sizeof(list_8c0a486e) / sizeof(*list);
        instructions = 85;
        break;
    case 0xc0a49e2u:
        list = list_8c0a49e2;
        count = sizeof(list_8c0a49e2) / sizeof(*list);
        instructions = 85;
        break;
    case 0xc0a4efcu:
        list = list_8c0a4efc;
        count = sizeof(list_8c0a4efc) / sizeof(*list);
        instructions = 74;
        break;
    case 0xc0a5068u:
        list = list_8c0a5068;
        count = sizeof(list_8c0a5068) / sizeof(*list);
        instructions = 74;
        break;
    case 0xc0a5f52u:
        list = list_8c0a5f52;
        count = sizeof(list_8c0a5f52) / sizeof(*list);
        instructions = 74;
        break;
    case 0xc0a609au:
        list = list_8c0a609a;
        count = sizeof(list_8c0a609a) / sizeof(*list);
        instructions = 74;
        break;
    default:
        return 0;
    }
    if (s->budget < instructions) {
        s->failed_pc = entry;
        return 0;
    }
    s->budget -= instructions;
    r[15] -= 4u;
    vf3_matrix_write(ram, r[15], r[14], 4);
    object = r[14] = vf3_matrix_read(ram, r[4] + 16u, 4);
    r[15] -= 4u;
    vf3_matrix_write(ram, r[15], r[16], 4);
    for (unsigned i = 0; i < count; ++i) {
        const literal_binding *binding = &list[i];
        if (binding->index_value >= 0)
            r[0] = (uint32_t)binding->index_value;
        r[4] = binding->command;
        r[5] = vf3_matrix_read(ram, object + binding->field_offset, 4);
        if (binding->return_pc)
            r[16] = binding->return_pc;
        else {
            r[16] = vf3_matrix_read(ram, r[15], 4);
            r[15] += 4u;
            r[14] = vf3_matrix_read(ram, r[15], 4);
            r[15] += 4u;
        }
        if (!vf3_matrix_family(0x0c0a2e06u, s, ram))
            return 0;
    }
    if (tail) {
        r[16] = vf3_matrix_read(ram, r[15], 4);
        r[15] += 4u;
        r[2] = tail;
        r[14] = vf3_matrix_read(ram, r[15], 4);
        r[15] += 4u;
        return vf3_matrix_family(tail, s, ram);
    }
    return 1;
}

