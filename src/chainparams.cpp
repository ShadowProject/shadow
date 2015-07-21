// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

#define PUSH_SEED( addr ) vSeeds.push_back(CDNSSeedData(addr, addr));

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x03;
        pchMessageStart[1] = 0x22;
        pchMessageStart[2] = 0x35;
        pchMessageStart[3] = 0x15;
        vAlertPubKey = ParseHex("0486bce1bac0d543f104cbff2bd23680056a3b9ea05e1137d2ff90eeb5e08472eb500322593a2cb06fbf8297d7beb6cd30cb90f98153b5b7cce1493749e41e0284");
        nDefaultPort = 31174;
        nRPCPort = 30174;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
        const char* pszTimestamp = "14/Apr/2014 No chowder for you, cause clams have feelings too";
        CTransaction txNew;
        txNew.nTime = 1397512438;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].SetEmpty();
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1397512438;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 2054231;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000c3ce6b3d823a35224a39798eca9ad889966aeb5a9da7b960ffb9869db35"));
        assert(genesis.hashMerkleRoot == uint256("0xef10b32afd53e4a6ebb8bdb0486c6acbe9b43afe3dfa538e913b89bb1319ff96"));



        PUSH_SEED("74.207.230.61")
	PUSH_SEED("88.198.207.8")
	PUSH_SEED("144.76.185.69")
	PUSH_SEED("172.245.10.158")
	PUSH_SEED("45.55.189.71")
	PUSH_SEED("104.236.83.126")
	PUSH_SEED("199.233.246.224")
	PUSH_SEED("109.236.85.42")
	PUSH_SEED("104.131.154.229")
	PUSH_SEED("5.189.139.227")
	PUSH_SEED("91.232.105.11")
	PUSH_SEED("37.187.156.122")
	PUSH_SEED("108.6.229.172")
	PUSH_SEED("52.24.129.50")
	PUSH_SEED("203.20.114.252")
	PUSH_SEED("178.238.105.141")
	PUSH_SEED("75.135.45.124")
	PUSH_SEED("97.101.130.66")
	PUSH_SEED("79.176.131.222")
	PUSH_SEED("46.163.71.123")
	PUSH_SEED("5.9.36.211")
	PUSH_SEED("97.122.191.38")
	PUSH_SEED("74.207.230.61")
	PUSH_SEED("108.73.85.204")
	PUSH_SEED("75.166.142.54")
	PUSH_SEED("207.216.183.115")
	PUSH_SEED("75.83.10.186")
	PUSH_SEED("31.208.74.7")
	PUSH_SEED("65.50.96.63")
	PUSH_SEED("162.213.195.88")
	PUSH_SEED("138.210.41.168")
	PUSH_SEED("120.24.76.48")
	PUSH_SEED("93.38.215.137")
	PUSH_SEED("92.244.112.153")
	PUSH_SEED("68.203.198.73")
	PUSH_SEED("142.129.85.105")
	PUSH_SEED("176.37.47.241")
	PUSH_SEED("100.2.8.214")
	PUSH_SEED("5.13.37.95")
	PUSH_SEED("69.143.123.14")
	PUSH_SEED("88.108.169.229")
	PUSH_SEED("186.205.143.209")

        base58Prefixes[PUBKEY_ADDRESS] = list_of(137);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(13);
        //CLAM Secret key, from old base58.h (release 1.4.2.1)  == 5 + 128
        base58Prefixes[SECRET_KEY]     = list_of(133);
        //BTC, LTC and DOGE secret keys
        base58Prefixes[SECRET_KEY_BTC] = list_of(128);
        base58Prefixes[SECRET_KEY_LTC] = list_of(176);
        base58Prefixes[SECRET_KEY_DOGE] = list_of(158);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xc4;
        pchMessageStart[1] = 0xf1;
        pchMessageStart[2] = 0xc0;
        pchMessageStart[3] = 0xdf;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("0471dc165db490094d35cde15b1f5d755fa6ad6f2b5ed0f340e3f17f57389c3c2af113a8cbcc885bde73305a553b5640c83021128008ddf882e856336269080496");
        nDefaultPort = 25714;
        nRPCPort = 25715;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 1279100;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000135b14723652fecaeb07a52cebf3f69512594eae48d139956bca67552441"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = list_of(111);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(196);
        base58Prefixes[SECRET_KEY]     = list_of(239);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1411111111;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 2;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";
        //assert(hashGenesisBlock == uint256("0x523dda6d336047722cbaf1c5dce622298af791bac21b33bf6e2d5048b2a13e3d"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
