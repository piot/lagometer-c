/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef LAGOMETER_LAGOMETER_H
#define LAGOMETER_LAGOMETER_H

#define LAGOMETER_WINDOW_SIZE (70)

#include <stddef.h>
#include <stdint.h>

typedef enum LagometerPacketStatus {
    LagometerPacketStatusReceived,
    LagometerPacketStatusDropped,
} LagometerPacketStatus;

typedef struct LagometerPacket {
    LagometerPacketStatus status;
    size_t latencyMs;
    size_t octetCount;
} LagometerPacket;

typedef struct LagometerPackets {
    LagometerPacket packets[LAGOMETER_WINDOW_SIZE];
    size_t readIndex;
    size_t writeIndex;
    size_t count;
    size_t capacity;
} LagometerPackets;

typedef struct Lagometer {
    LagometerPackets packets;
} Lagometer;

void lagometerInit(Lagometer* self);
void lagometerAddPacket(Lagometer* self, LagometerPacket packet);

#endif
