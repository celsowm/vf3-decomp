/* Real tail dispatch and callback 10. Other dispatch targets are explicitly
 * unsupported here; immutable pointers are read and checked, never replaced. */
#include "fight/audio_fight_internal.h"

int vf3_audio_fight_tail_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    const uint32_t alias=0x0c000000;
    STEP(0x097ff4);R(4)=0x0c29bcc4;
    STEP(0x097ff6);R(3)=0x20000;
    STEP(0x097ff8);R(2)=RD(R(4)+8,4);
    STEP(0x097ffa);R(6)=0x0c29b864;
    STEP(0x097ffc);condition(s,(R(2)&R(3))==0);
    STEP(0x097ffe);if(!(R(17)&1))goto done;
    STEP(0x098000);R(1)=RD(R(4)+8,4);
    STEP(0x098002);R(3)=0x30000000;
    STEP(0x098004);condition(s,(R(1)&R(3))==0);
    STEP(0x098006);if(R(17)&1)goto done;
    STEP(0x098008);R(2)=RD(R(4)+8,4);
    STEP(0x09800a);R(3)=0x40000000;
    STEP(0x09800c);condition(s,(R(2)&R(3))==0);
    STEP(0x09800e);int update=(R(17)&1)==0;
    STEP(0x098010);R(7)=0;
    if(update){
        STEP(0x098012);R(0)=41;
        STEP(0x098014);R(0)=signed_byte(RD(R(4)+R(0),1));
        STEP(0x098016);R(0)&=255;
        STEP(0x098018);condition(s,R(0)==3);
        STEP(0x09801a);if(R(17)&1)goto dispatch;
        STEP(0x09801c);R(0)=43;
        STEP(0x09801e);R(3)=signed_byte(RD(R(4)+R(0),1));
        STEP(0x098020);R(3)++;
        STEP(0x098022);WR(R(4)+R(0),R(3),1);
        STEP(0x098024);R(5)=RD(R(4)+52,4);
        STEP(0x098026);R(3)=RD(R(4)+56,4);
        STEP(0x098028);R(5)+=R(3);
        STEP(0x09802a);WR(R(4)+48,R(5),4);
        STEP(0x09802c);WR(R(4)+52,R(5),4);
        STEP(0x09802e);WR(R(4)+56,R(7),4);
    }
dispatch:
    STEP(0x098030);R(0)=16;
    STEP(0x098032);WR(R(6)+R(0),R(7),1);
    STEP(0x098034);R(0)=10;
    STEP(0x098036);R(3)=0x0c0968d0;
    STEP(0x098038);STEP(0x09803a);WR(R(6)+10,R(0),1);
    STEP(0x0968d0);R(4)=0x0c29b864;
    STEP(0x0968d2);R(15)-=4;
    STEP(0x0968d4);R(3)=RD(R(4)+12,4);
    STEP(0x0968d6);R(3)--;
    STEP(0x0968d8);WR(R(4)+12,R(3),4);
    STEP(0x0968da);R(0)=signed_byte(RD(R(4)+10,1));
    STEP(0x0968dc);R(5)=R(0)&255;
    STEP(0x0968de);R(0)=R(5);
    STEP(0x0968e0);WR(R(4)+8,R(0),1);
    STEP(0x0968e2);R(2)=0x80000000;
    STEP(0x0968e4);R(3)=0-R(5);
    STEP(0x0968e6);R(5)<<=2;
    STEP(0x0968e8);R(2)=logical_shift(R(2),R(3));
    STEP(0x0968ea);WR(R(4),R(2),4);
    STEP(0x0968ec);R(0)=0x0c10baa8;
    STEP(0x0968ee);R(3)=RD(R(0)+R(5),4);
    STEP(0x0968f0);R(2)=R(3);
    STEP(0x0968f2);WR(R(15),R(3),4);
    STEP(0x0968f4);STEP(0x0968f6);R(15)+=4;
    if(R(2)!=0x0c09a284){s->failed_pc=R(2);return 0;}
    return vf3_audio_fight_callback_c(s,ram);
done:
    STEP(0x09803c);STEP(0x09803e);s->pc=R(16);return ram->oob==0;
}

int vf3_audio_fight_callback_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    const uint32_t alias=0x0c000000;
    STEP(0x09a284);push(s,ram,R(14));
    STEP(0x09a286);push(s,ram,R(13));
    STEP(0x09a288);push(s,ram,R(16));
    STEP(0x09a28a);R(3)=0x0c0c5d86;
    STEP(0x09a28c);R(13)=0x0c29b864;
    STEP(0x09a28e);R(16)=alias+0x09a292;
    STEP(0x09a290);R(4)=51;
    if(!vf3_audio_submission_at_c(s,ram,alias))return 0;
    STEP(0x09a292);R(2)=0x0c096902;
    STEP(0x09a294);R(14)=0x0c29bb84;
    STEP(0x09a296);R(16)=alias+0x09a29a;
    STEP(0x09a298);R(4)=RD(R(14)+32,4);
    if(!vf3_audio_fight_render_c(s,ram,1))return 0;
    STEP(0x09a29a);R(3)=0x0c096902;
    STEP(0x09a29c);R(0)=68;
    STEP(0x09a29e);R(16)=alias+0x09a2a2;
    STEP(0x09a2a0);R(4)=RD(R(14)+R(0),4);
    if(!vf3_audio_fight_render_c(s,ram,1))return 0;
    const unsigned direct[6]={24,28,60,64,16,20};
    const uint32_t pcs[6]={0x09a2a2,0x09a2a8,0x09a2ae,0x09a2b4,0x09a2bc,0x09a2c2};
    for(unsigned i=0;i<6;++i){
        uint32_t pc=pcs[i];
        STEP(pc);R(i&1?3:2)=0x0c0968f8;
        if(i==3){STEP(pc+2);R(0)=direct[i];STEP(pc+4);R(16)=alias+pc+8;STEP(pc+6);R(4)=RD(R(14)+R(0),4);}
        else{STEP(pc+2);R(16)=alias+pc+6;STEP(pc+4);R(4)=RD(R(14)+direct[i],4);}
        if(!vf3_audio_fight_render_c(s,ram,0))return 0;
    }
    for(unsigned i=0;i<4;++i){
        uint32_t pc=0x09a2c8+i*8;
        STEP(pc);R(3)=0x0c0968f8;
        STEP(pc+2);R(0)=i==0?72:i==1?92:i==2?96:100;
        STEP(pc+4);R(16)=alias+pc+8;
        STEP(pc+6);R(4)=RD(R(14)+R(0),4);
        if(!vf3_audio_fight_render_c(s,ram,0))return 0;
    }
    STEP(0x09a2e8);R(0)=0x14c;
    STEP(0x09a2ea);R(1)=0;
    STEP(0x09a2ec);R(2)=0x08000000;
    STEP(0x09a2ee);R(4)=RD(R(14)+48,4);
    STEP(0x09a2f0);WR(R(4)+R(0),R(2),4);
    STEP(0x09a2f2);R(4)=RD(R(14)+32,4);
    STEP(0x09a2f4);R(3)=0xfff3ffff;
    STEP(0x09a2f6);R(2)=RD(R(4),4);
    STEP(0x09a2f8);R(2)&=R(3);
    STEP(0x09a2fa);WR(R(4),R(2),4);
    STEP(0x09a2fc);R(2)=0x0c0c3b40;
    STEP(0x09a2fe);R(0)=0xa28;
    STEP(0x09a300);R(16)=alias+0x09a304;
    STEP(0x09a302);WR(R(4)+R(0),R(1),1);
    if(!vf3_audio_fight_render_c(s,ram,2))return 0;
    STEP(0x09a304);R(0)=16;
    STEP(0x09a306);R(3)=39;
    STEP(0x09a308);WR(R(13)+R(0),R(3),1);
    STEP(0x09a30a);R(6)=0;
    STEP(0x09a30c);R(2)=128;
    STEP(0x09a30e);R(5)=R(6);
    STEP(0x09a310);WR(R(13)+12,R(2),4);
    STEP(0x09a312);R(0)=signed_byte(RD(R(13)+10,1));
    STEP(0x09a314);R(0)++;
    STEP(0x09a316);WR(R(13)+10,R(0),1);
    STEP(0x09a318);R(3)=0x0c038fe0;
    STEP(0x09a31a);R(16)=alias+0x09a31e;
    STEP(0x09a31c);R(4)=R(6);
    if(!vf3_audio_fight_render_c(s,ram,3))return 0;
    STEP(0x09a31e);R(6)=0;
    STEP(0x09a320);R(2)=0x0c0a7a0c;
    STEP(0x09a322);FR(5)=0;
    STEP(0x09a324);R(5)=R(6);
    STEP(0x09a326);FR(4)=0;
    STEP(0x09a328);R(16)=alias+0x09a32c;
    STEP(0x09a32a);R(4)=R(6);
    if(!vf3_audio_fight_render_c(s,ram,4))return 0;
    STEP(0x09a32c);R(16)=pop(s,ram);
    STEP(0x09a32e);R(13)=pop(s,ram);
    STEP(0x09a330);STEP(0x09a332);R(14)=pop(s,ram);
    STEP(0x09a334);push(s,ram,R(14));
    STEP(0x09a336);R(14)=0x0c29b864;
    STEP(0x09a338);push(s,ram,R(16));
    STEP(0x09a33a);R(3)=RD(R(14)+12,4);
    STEP(0x09a33c);condition(s,(int32_t)R(3)>0);
    STEP(0x09a33e);
    if(!(R(17)&1)){
        STEP(0x09a340);R(3)=0x0c0c5c94;
        STEP(0x09a342);R(4)=0x100a0;
        STEP(0x09a344);R(16)=alias+0x09a348;
        STEP(0x09a346);R(5)=0;
        if(!vf3_audio_request_c(s,ram,alias,1))return 0;
        STEP(0x09a348);R(2)=0x0c29bbb4;
        STEP(0x09a34a);R(0)=0x14c;
        STEP(0x09a34c);R(3)=0x10000000;
        STEP(0x09a34e);R(4)=RD(R(2),4);
        STEP(0x09a350);WR(R(4)+R(0),R(3),4);
        STEP(0x09a352);R(0)=4;
        STEP(0x09a354);WR(R(14)+10,R(0),1);
    }
    STEP(0x09a356);R(16)=pop(s,ram);
    STEP(0x09a358);STEP(0x09a35a);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
