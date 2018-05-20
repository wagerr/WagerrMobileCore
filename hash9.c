#include "hash9.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_blake.h"
#include "sha3/sph_bmw.h"
#include "sha3/sph_groestl.h"
#include "sha3/sph_jh.h"
#include "sha3/sph_keccak.h"
#include "sha3/sph_skein.h"
#include "sha3/sph_luffa.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_shavite.h"
#include "sha3/sph_simd.h"
#include "sha3/sph_echo.h"


void hash9(const char* input, char* output, uint32_t len)
{
    sph_blake512_context     ctx_blake;
    sph_bmw512_context       ctx_bmw;
    sph_groestl512_context   ctx_groestl;
    sph_jh512_context        ctx_jh;
    sph_keccak512_context    ctx_keccak;
    sph_skein512_context     ctx_skein;
    sph_luffa512_context     ctx_luffa;
    sph_cubehash512_context  ctx_cubehash;
    sph_shavite512_context   ctx_shavite;
    sph_simd512_context      ctx_simd;
    sph_echo512_context      ctx_echo;
    static unsigned char pblank[1];

    uint32_t hash0[16], hash1[16], hash2[16], hash3[16], hash4[16], hash5[16], hash6[16], hash7[16], hash8[16], hash9[16], hash10[16];

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, len );
    sph_blake512_close(&ctx_blake, hash0);
    
    sph_bmw512_init(&ctx_bmw);
    sph_bmw512 (&ctx_bmw, hash0, 64);
    sph_bmw512_close(&ctx_bmw, hash1);

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, hash1, 64);
    sph_groestl512_close(&ctx_groestl, hash2);

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, hash2, 64);
    sph_jh512_close(&ctx_jh, hash3);
    
    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak, hash3, 64);
    sph_keccak512_close(&ctx_keccak, hash4);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, hash4, 64);
    sph_skein512_close(&ctx_skein, hash5);
    
    sph_luffa512_init(&ctx_luffa);
    sph_luffa512 (&ctx_luffa, hash5, 64);
    sph_luffa512_close(&ctx_luffa, hash6);
    
    sph_cubehash512_init(&ctx_cubehash);
    sph_cubehash512 (&ctx_cubehash, hash6, 64);
    sph_cubehash512_close(&ctx_cubehash, hash7);
    
    sph_shavite512_init(&ctx_shavite);
    sph_shavite512(&ctx_shavite, hash7, 64);
    sph_shavite512_close(&ctx_shavite, hash8);
        
    sph_simd512_init(&ctx_simd);
    sph_simd512 (&ctx_simd, hash8, 64);
    sph_simd512_close(&ctx_simd, hash9);

    sph_echo512_init(&ctx_echo);
    sph_echo512 (&ctx_echo, hash9, 64);
    sph_echo512_close(&ctx_echo, hash10);

    memcpy(output, hash10, 32);
}

