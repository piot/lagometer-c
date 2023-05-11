/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <lagometer/lagometer.h>

static void lagometerPacketsInit(LagometerPackets* packets)
{
    packets->capacity = LAGOMETER_WINDOW_SIZE;
    packets->count = 0;
    packets->readIndex = 0;
    packets->writeIndex = 0;
}

static void addLagometerPackets(LagometerPackets* self, LagometerPacket packet)
{
    if (self->count == self->capacity) {
        self->readIndex = ++self->readIndex % self->capacity;
        self->count--;
    }

    self->packets[self->writeIndex] = packet;
    self->writeIndex = ++self->writeIndex % self->capacity;
    self->count++;
}

void lagometerInit(Lagometer* self)
{
    lagometerPacketsInit(&self->packets);
}

void lagometerAddPacket(Lagometer* self, LagometerPacket packet)
{
    addLagometerPackets(&self->packets, packet);
}
