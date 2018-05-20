//
//  BRBifrostParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRBifrostParams_h
#define BRBifrostParams_h

#include "BRChainParams.h"
#include "BRPeer.h"
#include "BRInt.h"

#define NPOW_TARGET_TIMESPAN (24*60*60)        // Coin 1 day
#define NPOW_TARGEY_SPACING (7*60)
#define COIN_BLOCK_DIFFICULTY_INTERVAL (NPOW_TARGET_TIMESPAN/NPOW_TARGEY_SPACING)

static const char *BRBifrostDNSSeeds[] = {
        "dnsseed.bifrostcoin.io"
        , NULL
};

static const char *BRBifrostTestNetDNSSeeds[] = {
    NULL
};

static const BRCheckPoint BRBifrostTestNetCheckpoints[] = {
    {       0, uint256("0000040df09b15ba874400ba995f342b82573864b9ee10c255dc4448ce334438"), 1517054400, 0x1d00ffff }       // timestamp and target bits probably not ok... chainparams.cpp
};


// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRBifrostCheckpoints[] = {
    {      0, uint256("000006e6fa091a20a38fe6f0212d03e5df72b44d76e2eb4246b4d366dbb01faf"), 1523854631, 0x1e0fffff },
    {      1, uint256("0000066df97de78fdde0f1cd5e78cf7ff17e1a8d6cbf4137afa99f1587fe7d2e"), 1523873817, 0x1e0fffff },
    {      2, uint256("00000b7cf8dc27bc4c98c91089adf58f5ec673e022c1b8ea0d5146d13bc49bb7"), 1523873820, 0x1e0fffff },
    {     61, uint256("0000001e7aa6833af7660e4e58d739560af233922fa8f043b103af40d8043ee7"), 1523876041, 0x1e01e76a },
    {    200, uint256("000001b018bb282b454914e42f9653b0e26fb8065562e50cbd9ce63283904b6a"), 1523885537, 0x1e02479a },
    {   1000, uint256("6ba268b0a5a87360b5942084a03e44b10b99bc9942153843be8f30be9946d709"), 1523922742, 0x1c021634 },
    {   5000, uint256("7b905329a6adabf53cba6a4c69fe4152a14a1154852f8459e7928f3566a99434"), 1524163348, 0x1b5a3fac },
    {  10000, uint256("35f56a42078ed92afa103fa5d8fe0684e0d5f800350f5230e3bf5e56f83fcc08"), 1524466756, 0x1b5d6109 },
    {  15000, uint256("278fa794765bcaf37b9b3f61c14584c2957b602cda5512f02a16dda8f702f751"), 1524769569, 0x1b51a826 }

};

static int BRBifrostVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
       return 1;
}

static int BRBifrostTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRBifrostParams = {
    BRBifrostDNSSeeds,
    9229,                // standardPort
    0xd6e1a2c5,          // magicNumber
    0, // services
    BRBifrostVerifyDifficulty,
    BRBifrostCheckpoints,
    sizeof(BRBifrostCheckpoints)/sizeof(*BRBifrostCheckpoints),
};

static const BRChainParams BRBifrostTestNetParams = {
    BRBifrostTestNetDNSSeeds,
    19229,               // standardPort
    0x86756453,          // magicNumber
    0, // services
    BRBifrostTestNetVerifyDifficulty,
    BRBifrostTestNetCheckpoints,
    sizeof(BRBifrostTestNetCheckpoints)/sizeof(*BRBifrostTestNetCheckpoints)
};

#endif // BRChainParams_h
