#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "crypto-algorithms/sha256.h"
#include "libbase58/libbase58.h"

void main(void) {
  SHA256_CTX ctx;
  unsigned char *input;
  unsigned char out[2+256/8];
  int i;

  unsigned char b58out[1024];
  size_t b58out_size = 1024;
  
  input = "Hello world\n";

  sha256_init(&ctx);
  sha256_update(&ctx, input, strlen(input));
  sha256_final(&ctx, 2+out);
  
  for(i = 0; i < 256/8; i++) {
    printf("%02x", out[2+i]);
  }
  puts("");

  out[0] = 0x12;
  out[1] = 32;
  if(!b58enc(b58out, &b58out_size, out, 2+256/8)) {
    puts("failed");
    return;
  }
  puts(b58out);
}
