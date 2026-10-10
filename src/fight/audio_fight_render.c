/* Rendering dependencies of callback 10. General packet/color publication is
 * retained; the overlay entry has the callback's proved zero-argument contract. */
#include "fight/audio_fight_internal.h"

static int object_flag(vf3_matrix_state*s,const vf3_ram_map*ram,int enable)
{
    const uint32_t alias=0x0c000000;
    if(enable){
        STEP(0x096902);R(0)=RD(R(4),4);
        STEP(0x096904);R(0)|=1;
        STEP(0x096906);STEP(0x096908);WR(R(4),R(0),4);
    }else{
        STEP(0x0968f8);R(1)=RD(R(4),4);
        STEP(0x0968fa);R(3)=0xfffffffe;
        STEP(0x0968fc);R(1)&=R(3);
        STEP(0x0968fe);STEP(0x096900);WR(R(4),R(1),4);
    }
    s->pc=R(16);return ram->oob==0;
}

static int style_count(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    const uint32_t alias=0x0c000000;
    STEP(0x0c3b40);push(s,ram,R(14));
    STEP(0x0c3b42);push(s,ram,R(13));
    STEP(0x0c3b44);push(s,ram,R(12));
    STEP(0x0c3b46);R(6)=0x0c29b864;
    STEP(0x0c3b48);R(15)-=8;
    STEP(0x0c3b4a);R(0)=0x98;
    STEP(0x0c3b4c);R(4)=0x0c29bcc4;
    STEP(0x0c3b4e);R(5)=RD(R(6)+R(0),4);
    STEP(0x0c3b50);R(0)=41;
    STEP(0x0c3b52);R(7)=R(4);
    STEP(0x0c3b54);R(12)=signed_byte(RD(R(7)+R(0),1));
    STEP(0x0c3b56);R(0)=42;
    STEP(0x0c3b58);R(13)=0x461;
    STEP(0x0c3b5a);R(12)&=255;
    STEP(0x0c3b5c);R(7)=signed_byte(RD(R(7)+R(0),1));
    STEP(0x0c3b5e);R(14)=R(12);
    STEP(0x0c3b60);R(14)-=3;
    STEP(0x0c3b62);condition(s,R(14)==0);
    STEP(0x0c3b64);R(13)+=R(4);
    STEP(0x0c3b66);R(7)&=255;
    STEP(0x0c3b68);int both=(R(17)&1)!=0;
    STEP(0x0c3b6a);R(7)-=2;
    if(!both){STEP(0x0c3b6c);R(7)=R(12);STEP(0x0c3b6e);R(7)-=2;}
    STEP(0x0c3b70);R(3)=RD(R(4)+8,4);
    STEP(0x0c3b72);R(0)=R(3);
    STEP(0x0c3b74);condition(s,(R(0)&4)==0);
    STEP(0x0c3b76);WR(R(15),R(3),4);
    STEP(0x0c3b78);
    if(!(R(17)&1)){
        STEP(0x0c3b7a);condition(s,R(7)==0);
        STEP(0x0c3b7c);
        if(R(17)&1){STEP(0x0c3b7e);R(12)=0x415;STEP(0x0c3b80);STEP(0x0c3b82);}
        else{STEP(0x0c3ba4);R(12)=0x41a;}
        STEP(0x0c3ba6);R(0)=0x413;
        STEP(0x0c3ba8);R(14)=0;
        STEP(0x0c3baa);R(12)+=R(4);
        STEP(0x0c3bac);R(3)=signed_byte(RD(R(4)+R(0),1));
        STEP(0x0c3bae);WR(R(15),R(3),4);
        do{
            STEP(0x0c3bb0);R(0)=R(14);
            STEP(0x0c3bb2);R(4)=signed_byte(RD(R(12)+R(0),1));
            STEP(0x0c3bb4);R(3)=13;
            STEP(0x0c3bb6);R(4)&=255;
            STEP(0x0c3bb8);condition(s,R(4)>=R(3));
            STEP(0x0c3bba);if(R(17)&1){STEP(0x0c3bbc);R(4)-=13;}
            STEP(0x0c3bbe);R(7)=R(4);
            STEP(0x0c3bc0);R(7)+=R(13);
            STEP(0x0c3bc2);WR(R(15)+4,R(7),4);
            STEP(0x0c3bc4);R(7)=signed_byte(RD(R(7),1));
            STEP(0x0c3bc6);R(3)=RD(R(15)+4,4);
            STEP(0x0c3bc8);R(7)&=255;
            STEP(0x0c3bca);R(7)--;
            STEP(0x0c3bcc);WR(R(3),R(7),1);
            STEP(0x0c3bce);R(3)=0;
            STEP(0x0c3bd0);condition(s,R(7)>R(3));
            STEP(0x0c3bd2);int keep=(R(17)&1)!=0;
            STEP(0x0c3bd4);R(14)++;
            if(!keep){
                STEP(0x0c3bd6);R(2)=0x80000000;
                STEP(0x0c3bd8);R(4)=0-R(4);
                STEP(0x0c3bda);R(0)=0x98;
                STEP(0x0c3bdc);R(2)=logical_shift(R(2),R(4));
                STEP(0x0c3bde);R(2)=~R(2);
                STEP(0x0c3be0);R(5)&=R(2);
                STEP(0x0c3be2);WR(R(6)+R(0),R(5),4);
            }
            STEP(0x0c3be4);R(3)=RD(R(15),4);
            STEP(0x0c3be6);condition(s,R(14)>=R(3));
            STEP(0x0c3be8);
        }while(!(R(17)&1));
        STEP(0x0c3bea);STEP(0x0c3bec);
    }else{
        STEP(0x0c3bee);condition(s,R(14)==0);
        STEP(0x0c3bf0);if(!(R(17)&1))goto done;
        STEP(0x0c3bf2);R(1)=0x0c29bb94;
        STEP(0x0c3bf4);condition(s,R(7)==0);
        STEP(0x0c3bf6);int first_actor=(R(17)&1)!=0;
        STEP(0x0c3bf8);R(4)=RD(R(1),4);
        if(!first_actor){STEP(0x0c3bfa);R(2)=0x0c29bb98;STEP(0x0c3bfc);R(4)=RD(R(2),4);}
        STEP(0x0c3bfe);R(0)=97;
        STEP(0x0c3c00);R(7)=signed_byte(RD(R(4)+R(0),1));
        STEP(0x0c3c02);R(7)&=255;
        STEP(0x0c3c04);R(4)=R(7);
        STEP(0x0c3c06);R(4)+=R(13);
        STEP(0x0c3c08);WR(R(15),R(4),4);
        STEP(0x0c3c0a);R(4)=signed_byte(RD(R(4),1));
        STEP(0x0c3c0c);R(3)=RD(R(15),4);
        STEP(0x0c3c0e);R(4)&=255;
        STEP(0x0c3c10);R(4)--;
        STEP(0x0c3c12);condition(s,R(4)==0);
        STEP(0x0c3c14);WR(R(3),R(4),1);
        STEP(0x0c3c16);
        if(R(17)&1){
            STEP(0x0c3c18);R(3)=0x80000000;
            STEP(0x0c3c1a);R(7)=0-R(7);
            STEP(0x0c3c1c);R(0)=0x98;
            STEP(0x0c3c1e);R(3)=logical_shift(R(3),R(7));
            STEP(0x0c3c20);R(3)=~R(3);
            STEP(0x0c3c22);R(5)&=R(3);
            STEP(0x0c3c24);WR(R(6)+R(0),R(5),4);
        }
    }
done:
    STEP(0x0c3c26);R(15)+=8;
    STEP(0x0c3c28);R(12)=pop(s,ram);
    STEP(0x0c3c2a);R(13)=pop(s,ram);
    STEP(0x0c3c2c);STEP(0x0c3c2e);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}

static int packet(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    const uint32_t alias=0x0c000000;
    STEP(0x0645f4);push(s,ram,R(14));
    STEP(0x0645f6);R(5)=0;
    STEP(0x0645f8);push(s,ram,R(13));
    STEP(0x0645fa);push(s,ram,R(16));
    STEP(0x0645fc);R(15)-=16;
    STEP(0x0645fe);R(13)=R(15);
    STEP(0x064600);R(3)=RD(R(4),4);
    STEP(0x064602);R(13)+=4;
    STEP(0x064604);R(14)=R(13);
    STEP(0x064606);R(6)=R(14);
    STEP(0x064608);WR(R(14),R(3),4);
    STEP(0x06460a);R(7)=R(14);
    STEP(0x06460c);R(2)=RD(R(4)+4,4);
    STEP(0x06460e);R(6)+=4;
    STEP(0x064610);WR(R(6),R(2),4);
    STEP(0x064612);R(7)+=8;
    STEP(0x064614);R(3)=RD(R(4)+8,4);
    STEP(0x064616);WR(R(7),R(3),4);
    STEP(0x064618);R(2)=0x0c16cc28;
    STEP(0x06461a);R(13)=RD(R(2),4);
    STEP(0x06461c);R(1)=0x0c16cc2c;
    STEP(0x06461e);R(3)=RD(R(1),4);
    STEP(0x064620);WR(R(15),R(3),4);
    STEP(0x064622);R(3)=0x0c16cc30;
    STEP(0x064624);R(4)=RD(R(3),4);
    STEP(0x064626);R(0)=0x0c16cb2c;
    STEP(0x064628);R(2)=R(5);
    STEP(0x06462a);R(5)++;
    STEP(0x06462c);R(2)<<=2;
    STEP(0x06462e);WR(R(0)+R(2),R(13),4);
    STEP(0x064630);R(1)=R(5);
    STEP(0x064632);R(5)++;
    STEP(0x064634);R(2)=RD(R(15),4);
    STEP(0x064636);R(1)<<=2;
    STEP(0x064638);WR(R(0)+R(1),R(2),4);
    STEP(0x06463a);R(1)=R(5);
    STEP(0x06463c);R(5)++;
    STEP(0x06463e);R(1)<<=2;
    STEP(0x064640);WR(R(0)+R(1),R(4),4);
    for(unsigned vertex=0;vertex<3;++vertex){
        for(unsigned field=0;field<4;++field){
            uint32_t pc=0x064642+vertex*48+field*12;
            STEP(pc);R(2)=R(5);
            if(vertex==2&&field==1){
                STEP(pc+2);R(5)++;
                STEP(pc+4);R(2)<<=2;
                STEP(pc+6);R(1)=RD(R(7),4);
                STEP(pc+8);R(1)=RD(R(1)+8,4);
            }else{
                STEP(pc+2);R(1)=RD(R(vertex==0?14:vertex==1?6:7),4);
                STEP(pc+4);R(5)++;
                STEP(pc+6);R(1)=RD(R(1)+(field==3?24:4+4*field),4);
                STEP(pc+8);R(2)<<=2;
            }
            STEP(pc+10);WR(R(0)+R(2),R(1),4);
        }
    }
    STEP(0x0646d2);R(5)<<=2;
    STEP(0x0646d4);R(2)=0x0c16cc24;
    STEP(0x0646d6);WR(R(2),R(5),4);
    STEP(0x0646d8);R(16)=alias+0x0646dc;
    STEP(0x0646da);R(4)=R(13);
    STEP(0x064512);R(3)=0x02000000;
    STEP(0x064514);condition(s,(R(3)&R(4))==0);
    STEP(0x064516);int plain=(R(17)&1)!=0;
    STEP(0x064518);R(5)=1;
    if(!plain){
        STEP(0x06451a);R(3)=0x01000000;
        STEP(0x06451c);condition(s,(R(3)&R(4))==0);
        STEP(0x06451e);int one=(R(17)&1)!=0;
        STEP(0x064520);R(5)++;
        if(!one){STEP(0x064522);R(5)++;}
        STEP(0x064524);R(3)=0x00400000;
        STEP(0x064526);condition(s,(R(4)&R(3))==0);
        STEP(0x064528);if(R(17)&1){STEP(0x06452a);R(5)++;}
    }
    STEP(0x06452c);STEP(0x06452e);R(0)=R(5);
    STEP(0x0646dc);R(4)=R(0);
    STEP(0x0646de);R(5)=0;
    STEP(0x0646e0);R(16)=alias+0x0646e4;
    STEP(0x0646e2);R(6)=R(5);
    STEP(0x0644e8);R(2)=0x0c16cc34;
    STEP(0x0644ea);condition(s,R(6)==0);
    STEP(0x0644ec);R(3)=7;
    STEP(0x0644ee);R(4)&=R(3);
    STEP(0x0644f0);R(4)<<=16;
    STEP(0x0644f2);R(4)<<=8;
    STEP(0x0644f4);STEP(0x0644f6);WR(R(2),R(4),4);
    STEP(0x064500);condition(s,R(5)==0);
    STEP(0x064502);
    STEP(0x06450e);STEP(0x064510);
    STEP(0x0646e4);R(2)=RD(R(14),4);
    STEP(0x0646e6);R(3)=RD(R(2)+12,4);
    STEP(0x0646e8);R(1)=0x0c16cc38;
    STEP(0x0646ea);WR(R(1),R(3),4);
    STEP(0x0646ec);R(0)=0;
    STEP(0x0646ee);R(15)+=16;
    STEP(0x0646f0);R(16)=pop(s,ram);
    STEP(0x0646f2);R(13)=pop(s,ram);
    STEP(0x0646f4);STEP(0x0646f6);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}

static void integer_float(vf3_matrix_state*s,unsigned n)
{ float value=(float)(int32_t)R(53);memcpy(&FR(n),&value,4); }

static int flat_quad(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    const uint32_t alias=0x0c000000;
    STEP(0x038fe0);push(s,ram,R(12));
    STEP(0x038fe2);R(0)=4;
    STEP(0x038fe4);push(s,ram,R(16));
    STEP(0x038fe6);R(7)=0x0c0ea394;
    STEP(0x038fe8);R(15)-=108;
    STEP(0x038fea);WR(R(7),R(4),4);
    STEP(0x038fec);WR(R(7)+4,R(5),4);
    STEP(0x038fee);WR(R(7)+8,R(6),4);
    STEP(0x038ff0);R(7)=R(15);
    STEP(0x038ff2);R(7)+=12;
    STEP(0x038ff4);R(3)=0xe0000000;
    STEP(0x038ff6);R(2)=R(7);
    STEP(0x038ff8);R(1)=R(2);
    STEP(0x038ffa);R(1)+=32;
    STEP(0x038ffc);WR(R(2),R(3),4);
    STEP(0x038ffe);FR(4)=0;
    STEP(0x039000);float_store(s,ram,4,R(2)+R(0));
    STEP(0x039002);R(0)=8;
    STEP(0x039004);float_store(s,ram,4,R(2)+R(0));
    STEP(0x039006);R(0)=0x0c039120;
    STEP(0x039008);float_load(s,ram,5,R(0));
    STEP(0x03900a);R(0)=12;
    STEP(0x03900c);float_store(s,ram,5,R(2)+R(0));
    STEP(0x03900e);WR(R(2)+16,R(4),4);
    STEP(0x039010);WR(R(2)+24,R(4),4);
    STEP(0x039012);WR(R(1),R(3),4);
    STEP(0x039014);R(12)=0x0c1a58e0;
    STEP(0x039016);R(0)=signed_word(RD(R(12)+4,2));
    STEP(0x039018);R(4)=R(0);
    STEP(0x03901a);R(0)=signed_word(RD(R(12)+10,2));
    STEP(0x03901c);condition(s,R(0)==0);
    STEP(0x03901e);
    if(R(17)&1){STEP(0x039030);R(4)=signed_word(R(4));}
    else{
        STEP(0x039020);R(4)=signed_word(R(4));
        STEP(0x039022);STEP(0x039024);condition(s,(R(4)&0x80000000)!=0);R(4)<<=1;
    }
    STEP(0x039032);R(53)=R(4);
    STEP(0x039034);R(0)=4;
    STEP(0x039036);R(4)=R(7);
    STEP(0x039038);R(4)+=64;
    STEP(0x03903a);integer_float(s,3);
    STEP(0x03903c);float_store(s,ram,3,R(1)+R(0));
    STEP(0x03903e);R(0)=8;
    STEP(0x039040);float_store(s,ram,4,R(1)+R(0));
    STEP(0x039042);R(0)=12;
    STEP(0x039044);float_store(s,ram,5,R(1)+R(0));
    STEP(0x039046);R(0)=4;
    STEP(0x039048);WR(R(1)+16,R(5),4);
    STEP(0x03904a);WR(R(1)+24,R(5),4);
    STEP(0x03904c);R(5)=0;
    STEP(0x03904e);R(3)=0xf0000000;
    STEP(0x039050);WR(R(4),R(3),4);
    STEP(0x039052);float_store(s,ram,4,R(4)+R(0));
    STEP(0x039054);R(0)=signed_word(RD(R(12)+6,2));
    STEP(0x039056);R(12)=R(15);
    STEP(0x039058);R(3)=R(0);
    STEP(0x03905a);R(53)=R(3);
    STEP(0x03905c);R(0)=8;
    STEP(0x03905e);integer_float(s,3);
    STEP(0x039060);float_store(s,ram,3,R(4)+R(0));
    STEP(0x039062);R(0)=12;
    STEP(0x039064);float_store(s,ram,5,R(4)+R(0));
    STEP(0x039066);WR(R(4)+16,R(6),4);
    STEP(0x039068);WR(R(4)+24,R(6),4);
    STEP(0x03906a);R(6)=32;
    STEP(0x03906c);WR(R(12),R(2),4);
    STEP(0x03906e);WR(R(12)+4,R(1),4);
    STEP(0x039070);WR(R(12)+8,R(4),4);
    STEP(0x039072);R(3)=0x0c05e3d6;
    STEP(0x039074);R(16)=alias+0x039078;
    STEP(0x039076);R(4)=R(12);
    STEP(0x05e3d6);R(3)=R(5);
    STEP(0x05e3d8);R(0)=0x0c0eae48;
    STEP(0x05e3da);R(3)<<=2;
    STEP(0x05e3dc);push(s,ram,R(16));
    STEP(0x05e3de);R(15)-=4;
    STEP(0x05e3e0);WR(R(15),R(5),4);
    STEP(0x05e3e2);R(3)=RD(R(0)+R(3),4);
    STEP(0x05e3e4);R(16)=alias+0x05e3e8;
    STEP(0x05e3e6);
    if(R(3)!=0x0c0645f4){s->failed_pc=R(3);return 0;}
    if(!packet(s,ram))return 0;
    STEP(0x05e3e8);R(3)=0x0c16cb2c;
    STEP(0x05e3ea);R(2)=0xfff00000;
    STEP(0x05e3ec);R(1)=RD(R(3),4);
    STEP(0x05e3ee);R(1)&=R(2);
    STEP(0x05e3f0);WR(R(3),R(1),4);
    STEP(0x05e3f2);R(15)+=4;
    STEP(0x05e3f4);R(16)=pop(s,ram);
    STEP(0x05e3f6);STEP(0x05e3f8);
    STEP(0x039078);R(15)+=108;
    STEP(0x03907a);R(16)=pop(s,ram);
    STEP(0x03907c);STEP(0x03907e);R(12)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}

static int publish_color(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    const uint32_t alias=0x0c000000;
    STEP(0x03b300);push(s,ram,R(14));
    STEP(0x03b302);R(7)=R(4);
    STEP(0x03b304);push(s,ram,R(16));
    STEP(0x03b306);R(7)>>=16;
    STEP(0x03b308);R(5)=R(4);
    STEP(0x03b30a);R(7)>>=8;
    STEP(0x03b30c);R(6)=R(4);
    STEP(0x03b30e);R(7)=signed_byte(R(7));
    STEP(0x03b310);R(15)-=4;
    STEP(0x03b312);R(0)=R(7);
    STEP(0x03b314);R(14)=R(15);
    STEP(0x03b316);R(5)>>=16;
    STEP(0x03b318);WR(R(14)+3,R(0),1);
    STEP(0x03b31a);R(5)=signed_word(R(5));
    STEP(0x03b31c);R(0)=R(5);
    STEP(0x03b31e);R(3)=0xfffffff8;
    STEP(0x03b320);WR(R(14)+2,R(0),1);
    STEP(0x03b322);R(6)=(uint32_t)((int32_t)R(6)>>8);
    STEP(0x03b324);R(0)=R(6);
    STEP(0x03b326);WR(R(14)+1,R(0),1);
    STEP(0x03b328);WR(R(14),R(4),1);
    STEP(0x03b32a);R(3)=RD(R(14),4);
    STEP(0x03b32c);R(2)=0x0c05e1b2;
    STEP(0x03b32e);R(16)=alias+0x03b332;
    STEP(0x03b330);push(s,ram,R(3));
    STEP(0x05e1b2);push(s,ram,R(16));
    STEP(0x05e1b4);R(4)=176;
    STEP(0x05e1b6);R(3)=0x0c060d14;
    STEP(0x05e1b8);R(16)=alias+0x05e1bc;
    STEP(0x05e1ba);R(5)=RD(R(15)+4,4);
    STEP(0x060d14);R(3)=0xa05f8000;
    STEP(0x060d16);R(4)+=R(3);
    STEP(0x060d18);WR(R(4),R(5),4);
    STEP(0x060d1a);STEP(0x060d1c);R(0)=1;
    STEP(0x05e1bc);R(16)=pop(s,ram);
    STEP(0x05e1be);STEP(0x05e1c0);R(0)=0;
    STEP(0x03b332);R(15)+=8;
    STEP(0x03b334);R(16)=pop(s,ram);
    STEP(0x03b336);STEP(0x03b338);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}

static int zero_overlay(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    const uint32_t alias=0x0c000000;
    /* Callback 10 calls with all integer and float arguments zero. Reject
     * general interpolation and double-width variants instead of inventing them. */
    if(R(4)||R(5)||R(6)||FR(4)||FR(5)||(R(18)&0x180000u)){
        s->failed_pc=alias+0x0a7a0c;return 0;
    }
    STEP(0x0a7a0c);push(s,ram,R(14));
    STEP(0x0a7a0e);R(7)=R(4);
    STEP(0x0a7a10);push(s,ram,R(13));
    STEP(0x0a7a12);R(7)<<=16;
    STEP(0x0a7a14);R(15)-=float_width(s);float_store(s,ram,15,R(15));
    STEP(0x0a7a16);R(14)=R(7);
    STEP(0x0a7a18);R(5)<<=8;
    STEP(0x0a7a1a);R(4)=R(6);
    STEP(0x0a7a1c);push(s,ram,R(16));
    STEP(0x0a7a1e);R(14)|=R(5);
    STEP(0x0a7a20);R(14)|=R(4);
    STEP(0x0a7a22);R(15)-=4;
    STEP(0x0a7a24);float_store(s,ram,4,R(15));
    STEP(0x0a7a26);R(3)=0xff000000;
    STEP(0x0a7a28);R(0)=0x138;
    STEP(0x0a7a2a);R(13)=0x0c2a5ecc;
    STEP(0x0a7a2c);R(14)|=R(3);
    STEP(0x0a7a2e);float_move(s,15,5);
    STEP(0x0a7a30);WR(R(13)+R(0),R(14),4);
    STEP(0x0a7a32);R(2)=0x0c03b300;
    STEP(0x0a7a34);R(16)=alias+0x0a7a38;
    STEP(0x0a7a36);R(4)=R(14);
    if(!publish_color(s,ram))return 0;
    STEP(0x0a7a38);R(3)=0x0c038fe0;
    STEP(0x0a7a3a);R(5)=R(14);
    STEP(0x0a7a3c);R(6)=R(14);
    STEP(0x0a7a3e);R(16)=alias+0x0a7a42;
    STEP(0x0a7a40);R(4)=R(14);
    if(!flat_quad(s,ram))return 0;
    STEP(0x0a7a42);float_load(s,ram,2,R(15));
    STEP(0x0a7a44);R(5)=0;
    STEP(0x0a7a46);FR(3)=0;
    STEP(0x0a7a48);R(1)=0;
    STEP(0x0a7a4a);condition(s,0); /* fcmp/gt: both proved arguments are zero. */
    STEP(0x0a7a4c);R(14)=0x13c;
    STEP(0x0a7a4e);R(4)=128;
    STEP(0x0a7a50);R(14)+=R(13);
    STEP(0x0a7a52);FR(6)=0;
    STEP(0x0a7a54);STEP(0x0a7a56);R(1)+=R(14);
    STEP(0x0a7a58);R(6)=R(5);
    STEP(0x0a7a5a);R(5)=R(1);
    do{
        STEP(0x0a7a5c);R(6)++;
        STEP(0x0a7a5e);float_store(s,ram,6,R(5));
        STEP(0x0a7a60);condition(s,(int32_t)R(6)>(int32_t)R(4));
        STEP(0x0a7a62);int stop=(R(17)&1)!=0;
        STEP(0x0a7a64);R(5)+=4;
        if(stop)break;
    }while(1);
    STEP(0x0a7a66);R(0)=0x0c0a7ad4;
    STEP(0x0a7a68);float_load(s,ram,3,R(0));
    STEP(0x0a7a6a);R(0)=0x134;
    STEP(0x0a7a6c);STEP(0x0a7a6e);float_store(s,ram,3,R(13)+R(0));
    STEP(0x0a7b02);R(15)+=4;
    STEP(0x0a7b04);R(0)=RD(R(13),4);
    STEP(0x0a7b06);R(16)=pop(s,ram);
    STEP(0x0a7b08);R(0)|=1;
    STEP(0x0a7b0a);WR(R(13),R(0),4);
    STEP(0x0a7b0c);R(5)=0;
    STEP(0x0a7b0e);float_load(s,ram,15,R(15));R(15)+=float_width(s);
    STEP(0x0a7b10);R(3)=0x0c059508;
    STEP(0x0a7b12);R(13)=pop(s,ram);
    STEP(0x0a7b14);R(4)=0x0c0a7b56;
    STEP(0x0a7b16);STEP(0x0a7b18);R(14)=pop(s,ram);
    STEP(0x059508);push(s,ram,R(16));
    STEP(0x05950a);R(7)=R(5);
    STEP(0x05950c);R(3)=0x0c0eadec;
    STEP(0x05950e);R(15)-=8;
    STEP(0x059510);WR(R(15),R(4),4);
    STEP(0x059512);WR(R(15)+4,R(5),4);
    STEP(0x059514);R(6)=RD(R(15),4);
    STEP(0x059516);R(5)=0;
    STEP(0x059518);R(16)=alias+0x05951c;
    STEP(0x05951a);R(4)=RD(R(3),4);
    STEP(0x0594b4);push(s,ram,R(16));
    STEP(0x0594b6);R(0)=R(17);
    STEP(0x0594b8);R(3)=0xffffff0f;
    STEP(0x0594ba);R(15)-=8;
    STEP(0x0594bc);R(0)>>=2;
    STEP(0x0594be);R(0)>>=2;
    STEP(0x0594c0);R(0)&=15;
    STEP(0x0594c2);WR(R(15),R(0),4);
    STEP(0x0594c4);R(0)=R(17);
    STEP(0x0594c6);R(0)&=R(3);
    STEP(0x0594c8);R(0)|=240;
    STEP(0x0594ca);R(17)=R(0);
    STEP(0x0594cc);condition(s,R(6)==0);
    STEP(0x0594ce);
    STEP(0x0594d0);R(3)=0x230;
    STEP(0x0594d2);R(5)<<=2;
    STEP(0x0594d4);R(2)=0x230;
    STEP(0x0594d6);R(3)+=R(4);
    STEP(0x0594d8);condition(s,(R(5)&0x80000000)!=0);R(5)<<=1;
    STEP(0x0594da);R(2)+=R(4);
    STEP(0x0594dc);WR(R(15)+4,R(5),4);
    STEP(0x0594de);R(5)+=R(3);
    STEP(0x0594e0);WR(R(5),R(6),4);
    STEP(0x0594e2);R(3)=RD(R(15)+4,4);
    STEP(0x0594e4);R(2)+=R(3);
    STEP(0x0594e6);STEP(0x0594e8);WR(R(2)+4,R(7),4);
    STEP(0x0594ee);R(3)=R(17);
    STEP(0x0594f0);R(2)=0xffffff0f;
    STEP(0x0594f2);R(0)=RD(R(15),4);
    STEP(0x0594f4);R(0)&=15;
    STEP(0x0594f6);R(0)<<=2;
    STEP(0x0594f8);R(0)<<=2;
    STEP(0x0594fa);R(3)&=R(2);
    STEP(0x0594fc);R(0)|=R(3);
    STEP(0x0594fe);R(17)=R(0);
    STEP(0x059500);R(15)+=8;
    STEP(0x059502);R(16)=pop(s,ram);
    STEP(0x059504);STEP(0x059506);
    STEP(0x05951c);R(15)+=8;
    STEP(0x05951e);R(16)=pop(s,ram);
    STEP(0x059520);STEP(0x059522);R(0)=0;
    s->pc=R(16);return ram->oob==0;
}

int vf3_audio_fight_render_c(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned kind)
{
    switch(kind){
    case 0:return object_flag(s,ram,0);
    case 1:return object_flag(s,ram,1);
    case 2:return style_count(s,ram);
    case 3:return flat_quad(s,ram);
    case 4:return zero_overlay(s,ram);
    default:return 0;
    }
}
