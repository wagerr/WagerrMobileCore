//
//  BRCoinParams.h
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

#ifndef BRCoinParams_h
#define BRCoinParams_h

#include "BRChainParams.h"
#include "BRPeer.h"
#include "BRInt.h"

#define NPOW_TARGET_TIMESPAN (24*60*60)        // Coin 1 day
#define NPOW_TARGEY_SPACING (7*60)
#define COIN_BLOCK_DIFFICULTY_INTERVAL (NPOW_TARGET_TIMESPAN/NPOW_TARGEY_SPACING)

static const char *BRCoinDNSSeeds[] = {
    "main.seederv1.wgr.host", "main.seederv2.wgr.host", "main.devseeder1.wgr.host", "main.devseeder2.wgr.host"
    , NULL
};

static const char *BRCoinTestNetDNSSeeds[] = {
    "testnet-seeder-01.wgr.host", "testnet.testnet-seeder-01.wgr.host",
    "testnet-seeder-02.wgr.host", "testnet.testnet-seeder-02.wgr.host"
    , NULL
};

static const char *BRCoinBetAddresses[] = {
    "WcsijutAF46tSLTcojk9mR9zV9wqwUUYpC",
    "Weqz3PFBq3SniYF5HS8kuj72q9FABKzDrP"
    , NULL
};

static const char *BRCoinTestnetBetAddresses[] = {
    "TGFKr64W3tTMLZrKBhMAou9wnQmdNMrSG2",     // Oracle Masternode Event & Result Posting Wallet Address (Testnet).
    "TWM5BQzfjDkBLGbcDtydfuNcuPfzPVSEhc"
    , NULL
};

static const BRCheckPoint BRCoinTestNetCheckpoints[] = {
    {       1, uint256("0000098cc93ece2804776d2e9eda2d01e2ff830d80bab22500821361259f8aa3"), 1588736964, 0x1e0fffff},
    {     450, uint256("3cec3911fdf321a22b8109ca95ca28913e6b51f0d80cc6d2b2e30e1f2a6115c0"), 1588752580, 0x1c090c51},
    {     469, uint256("d69d843cd63d333cfa3ff4dc0675fa320d6ef8cab7ab1a73bf8a1482210f93ce"), 1588752598, 0x1c038cb2},
    {    1100, uint256("fa462709a1f3cf81d699ffbd45440204aa4d38de84c2da1fc8b3ff15c3c7a95f"), 1588780440, 0x1a100e36},
    {    2000, uint256("a5aab45e4e2345715adf79774d661a5bb9b2a2efd001c339df5678418fb51409"), 1588834261, 0x1a06ea8a}

};


// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRCoinCheckpoints[] = {
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
    {  695857, uint256("680a170b5363f308cc0698a53ab6a83209dab06c138c98f91110f9e11e273778"), 1560967688, 0x1a508433 },
    {  720000, uint256("63fc356380b3b8791e83a9d63d059ccc8d0e65dab703575ef4ca070e26e02fc7"), 1562424165, 0x1a47f2b0 },
    {  732900, uint256("5d832b3de9b207e03366fb8d4da6265d52015f5d1bd8951a656b5d4508a1da8e"), 1563200722, 0x1a40bac9 },
    {  891270, uint256("eedb1794ca9267fb0ef88aff27afdd376ac93a54491a7b812cbad4b6c2e28d25"), 1572600959, 0x1a2be1d8 }
};

static int BRCoinVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1;
}

static int BRCoinTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRCoinParams = {
    BRCoinDNSSeeds,
    55002,                // standardPort
    0xfd612d84,          // magicNumber
    0, // services
    BRCoinVerifyDifficulty,
    BRCoinCheckpoints,
    sizeof(BRCoinCheckpoints)/sizeof(*BRCoinCheckpoints),
    BRCoinBetAddresses
};

static const BRChainParams BRCoinTestNetParams = {
    BRCoinTestNetDNSSeeds,
    55004,               // standardPort
    0x99d19e87,          // magicNumber
    0, // services
    BRCoinTestNetVerifyDifficulty,
    BRCoinTestNetCheckpoints,
    sizeof(BRCoinTestNetCheckpoints)/sizeof(*BRCoinTestNetCheckpoints),
    BRCoinTestnetBetAddresses
};

#endif // BRChainParams_h
