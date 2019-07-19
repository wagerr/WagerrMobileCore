//
//  BRWagerrParams.h
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

#ifndef BRWagerrParams_h
#define BRWagerrParams_h

#include "BRChainParams.h"
#include "BRPeer.h"
#include "BRInt.h"

#define NPOW_TARGET_TIMESPAN (24*60*60)        // Coin 1 day
#define NPOW_TARGEY_SPACING (7*60)
#define COIN_BLOCK_DIFFICULTY_INTERVAL (NPOW_TARGET_TIMESPAN/NPOW_TARGEY_SPACING)

static const char *BRWagerrDNSSeeds[] = {
        "main.seederv1.wgr.host", "main.seederv2.wgr.host", "main.devseeder1.wgr.host", "main.devseeder2.wgr.host"
        , NULL
};

static const char *BRWagerrTestNetDNSSeeds[] = {
        "testnet-seeder-01.wgr.host", "testnet.testnet-seeder-01.wgr.host",
        "testnet-seeder-02.wgr.host", "testnet.testnet-seeder-02.wgr.host"
        , NULL
};

static const char *BRWagerrBetAddresses[] = {
        "WTogNAzaHf9oEbBoAv9RA49FdxyWaGLmdZ"
        , NULL
};

static const char *BRWagerrTestnetBetAddresses[] = {
        "TGFKr64W3tTMLZrKBhMAou9wnQmdNMrSG2",     // Oracle Masternode Event & Result Posting Wallet Address (Testnet).
        "TWM5BQzfjDkBLGbcDtydfuNcuPfzPVSEhc"
        , NULL
};

static const BRCheckPoint BRWagerrTestNetCheckpoints[] = {
    {       1, uint256("00000385558ec1b9af7f939e1626a3116b9fb988c86c2f915e6451e8efcd0521"), 1517054400, 0x1d00ffff},
    {   20040, uint256("03a92984c2deba55ac8f9e8194b1bc745fbad9f7a0f3ed94ebb8c372935bed9c"), 1517054400, 0x1d00ffff},   // tx 40878
    {   93286, uint256("dc68d97761ceac8c177a81487569bfe92b720f513fbbf5c2184988f1d74c5061"), 1517054400, 0x1d00ffff} // tx 227380
};


// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRWagerrCheckpoints[] = {
    {       1, uint256("000001364c4ed20f1b240810b5aa91fee23ae9b64b6e746b594b611cf6d8c87b"), 1518743781, 0x1e0fffff },          // First PoW premine block
    {     101, uint256("0000005e89a1fab52bf996e7eb7d653962a0eb064c16c09887504797deb7feaf"), 1518746959, 0x1d769f71 },          // Last premine block
    {    1001, uint256("0000002a314058a8f61293e18ddbef5664a2097ac0178005f593444549dd5b8c"), 1518803284, 0x1d307420 },          // Last PoW block
    {    5530, uint256("b3a8e6eb90085394c1af916d5690fd5b83d53c43cf60c7b6dd1e904e0ede8e88"), 1519055199, 0x1a0a131e },          // Block on which switch off happened, 5531, 5532 differed
    {   14374, uint256("61dc2dbb225de3146bc59ab96dedf48047ece84d004acaf8f386ae7a7d074983"), 1519653932, 0x1a0dde43 },
    {   70450, uint256("ea83266a9dfd7cf92a96aa07f86bdf60d45850bd47c175745e71a1aaf60b4091"), 1523055044, 0x1a0cb4c0 },
    {  257142, uint256("eca635870323e7c0785fec1e663f4cb8645b7e84b5df4511ba4c189e580bfafd"), 1534374855, 0x1a14f60f },
    {  290000, uint256("5a70e614a2e6035be0fa1dd1a67bd6caa0a78e396e889aac42bbbc08e11cdabd"), 1536367184, 0x1a0d4db7 },
    {  294400, uint256("01be3c3c84fd6063ba27080996d346318242d5335efec936408c1e1ae3fdb4a1"), 1536634958, 0x1a14c311 },
    {  320000, uint256("9060f8d44058c539653f37eaac4c53de7397e457dda264c5ee1be94293e9f6bb"), 1538190282, 0x1a15305d },         // tx 671130
    {  695857, uint256("680a170b5363f308cc0698a53ab6a83209dab06c138c98f91110f9e11e273778"), 1560967688, 0x1a508433 }
};

static int BRWagerrVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
       return 1;
}

static int BRWagerrTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRWagerrParams = {
    BRWagerrDNSSeeds,
    55002,                // standardPort
    0xfd612d84,          // magicNumber
    0, // services
    BRWagerrVerifyDifficulty,
    BRWagerrCheckpoints,
    sizeof(BRWagerrCheckpoints)/sizeof(*BRWagerrCheckpoints),
    BRWagerrBetAddresses
};

static const BRChainParams BRWagerrTestNetParams = {
    BRWagerrTestNetDNSSeeds,
    55004,               // standardPort
    0x99d19e87,          // magicNumber
    0, // services
    BRWagerrTestNetVerifyDifficulty,
    BRWagerrTestNetCheckpoints,
    sizeof(BRWagerrTestNetCheckpoints)/sizeof(*BRWagerrTestNetCheckpoints),
    BRWagerrTestnetBetAddresses
};

#endif // BRChainParams_h
