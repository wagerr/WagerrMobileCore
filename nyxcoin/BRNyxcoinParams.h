//
//  BRNyxParams.h
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

#ifndef BRNyxParams_h
#define BRNyxParams_h

#include "BRChainParams.h"
#include "BRPeer.h"
#include "BRInt.h"

#define NPOW_TARGET_TIMESPAN (24*60*60)        // Nyx 1 day
#define NPOW_TARGEY_SPACING (7*60)
#define COIN_BLOCK_DIFFICULTY_INTERVAL (NPOW_TARGET_TIMESPAN/NPOW_TARGEY_SPACING)

static const char *BRNyxDNSSeeds[] = {
        "node1.nyxcoin.org", "node2.nyxcoin.org", "node3.nyxcoin.org","node4.nyxcoin.org","node5.nyxcoin.org"
        , NULL
};

static const char *BRNyxTestNetDNSSeeds[] = {
    "node1.nyxcoin.org", "node2.nyxcoin.org", NULL
};

static const BRCheckPoint BRNyxTestNetCheckpoints[] = {
    {       0, uint256("00000d72d411dc83f7f09f88c7d57c77d3dc061eec14806a958c051902602636"), 1517054400, 0x1d00ffff }       // timestamp and target bits probably not ok... chainparams.cpp
};


// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRNyxCheckpoints[] = {
    {      175, uint256("0000008324b22109a4cd33aa15181a81e13b0ed6b4724fd4b0b9355637a65058"), 1517077419, 0x1e008f13 },
    {    5175, uint256("000000000002b5b8886acc2c0613f871e1eff192c68bde64fded61a337652065"), 1517722408, 0x1c022475 },
    {   25175, uint256("000000000323b956e72290f25c3f3b0c29e4282b35902406a2a89e097efe94c8"), 1520279015, 0x1c03a0df },
    {   55254, uint256("000000000067f916f4333284fca23ed3067efc875af63a0cc8342d8704b99248"), 1524117018, 0x1c081c0d }
};

static int BRNyxVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
       return 1;
}

static int BRNyxTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRNyxParams = {
    BRNyxDNSSeeds,
    4330,                // standardPort
    0xcc7b3caf,          // magicNumber
    0, // services
    BRNyxVerifyDifficulty,
    BRNyxCheckpoints,
    sizeof(BRNyxCheckpoints)/sizeof(*BRNyxCheckpoints),
};

static const BRChainParams BRNyxTestNetParams = {
    BRNyxTestNetDNSSeeds,
    4332,               // standardPort
    0x2cbd1f3b,          // magicNumber
    0, // services
    BRNyxTestNetVerifyDifficulty,
    BRNyxTestNetCheckpoints,
    sizeof(BRNyxTestNetCheckpoints)/sizeof(*BRNyxTestNetCheckpoints)
};

#endif // BRChainParams_h
