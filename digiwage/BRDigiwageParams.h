//
//  BRDigiwageParams.h
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

#ifndef BRDigiwageParams_h
#define BRDigiwageParams_h

#include "BRChainParams.h"
#include "BRPeer.h"
#include "BRInt.h"

#define NPOW_TARGET_TIMESPAN (24*60*60)        // Digiwage 1 day
#define NPOW_TARGEY_SPACING (7*60)
#define COIN_BLOCK_DIFFICULTY_INTERVAL (NPOW_TARGET_TIMESPAN/NPOW_TARGEY_SPACING)

static const char *BRDigiwageDNSSeeds[] = {
        "dnsseed1.digiwage.org", "dnsseed2.digiwage.org", "dnsseed3.digiwage.org"
        ,"207.246.103.145", "207.246.103.145", "45.32.80.64", "45.32.80.64","45.32.65.59", "45.32.65.59","104.238.140.145", "104.238.140.145"
        ,"104.238.186.15", "140.82.38.254"
        , NULL
};

static const char *BRDigiwageTestNetDNSSeeds[] = {
    "testnet-seed.digiwagedot.io", "test.dnsseed.masternode.io", NULL
};

static const BRCheckPoint BRDigiwageTestNetCheckpoints[] = {
    {       1, uint256("18b37b60b422ea27d57ceea9dd794b5f74c561565ecc03e85a22ecdf74cbb33a"), 1511964848, 0x1d00ffff }       // timestamp and target bits probably not ok... chainparams.cpp
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRDigiwageCheckpoints[] = {
    {      0, uint256("000009f854e700ab62642c7d3e94be65a1d8c112384f5edfb4b2b3fa3fecaef6"), 1522130562, 0x1e0ffff0 },
    {    5, uint256("000009fd6256cf5f48edc32c1d3f73a84b0fcfe17aaca378a06e0f28f60dd53c"), 1522163501, 0x1e0fffff },
    {   100, uint256("00000d9e760c378c601da0671509010192bab447f31a7ddb126d0300348fd5ef"), 1522182880, 0x1e0fffff }
};

static int BRDigiwageVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
       return 1;
}

static int BRDigiwageTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRDigiwageParams = {
    BRDigiwageDNSSeeds,
    46003,                // standardPort
    0xd6a7f4c1,          // magicNumber
    0, // services
    BRDigiwageVerifyDifficulty,
    BRDigiwageCheckpoints,
    sizeof(BRDigiwageCheckpoints)/sizeof(*BRDigiwageCheckpoints),
};

static const BRChainParams BRDigiwageTestNetParams = {
    BRDigiwageTestNetDNSSeeds,
    46005,               // standardPort
    0x5e18c3d4,          // magicNumber
    0, // services
    BRDigiwageTestNetVerifyDifficulty,
    BRDigiwageTestNetCheckpoints,
    sizeof(BRDigiwageTestNetCheckpoints)/sizeof(*BRDigiwageTestNetCheckpoints)
};

#endif // BRChainParams_h
