#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 14 // 13 + 1 for the null terminator

typedef struct {
  int version;
  char buffer[BUFFER_SIZE];
} Packet;

int main() {
  printf("Hello, World!\n");

  Packet *packet = (Packet *)malloc(sizeof(Packet));

  if (packet == NULL) {
    fprintf(stderr, "Failed to allocate memory for packet\n");
    return EXIT_FAILURE;
  }

  packet->version = 1;
  memcpy(packet->buffer, "Hello, world!", 13);

  // We add the null terminator because its possible
  // that the memory location at packet->buffer[13]
  // is not null. So we are chosing to be explicit
  // about it.
  packet->buffer[13] = '\0';

  printf("Packet size: %lu\n", sizeof(Packet));
  printf("Packet version: %d\n", packet->version);
  printf("Packet buffer: %s\n", packet->buffer);

  for (int i = 0; i < BUFFER_SIZE; i++) {
    printf("Packet buffer[%d]: %c -> %d\n", i, packet->buffer[i],
           packet->buffer[i]);
  }

  free(packet);

  return EXIT_SUCCESS;
}
