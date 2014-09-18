// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2014 SchillingCoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
        ( 0, uint256("0x186ecfbf1d057a4ba54ae1f638edb6d4a71cdde56b33fa1a6d4743a48fe895be"))
		( 1, uint256("0x6826b08fbb1e8a096c1ab1e8c0857475192638afd9c03a99689407b1c414695c"))
		( 5, uint256("0x9f1204a737970e28510fa7dbae49ac8ba335f270108fed43de8b8fd364b9bae0"))
		( 10, uint256("0x471c6c3a6dcfba108d854d6dbd7caa4abebdb7882fa20365db9f0303c0d432f7"))
		( 15, uint256("0x268158df9f44a57702d6ae49df372f06e2b37667be3ff9d2bb58378290256f6d"))
		( 18, uint256("0x69b5df0071930d044f2689810c359bdf304a5ba27e356fb8b8d955e2eaffe4f5"))
		( 20, uint256("0x3c27b908a58d659056922ee28f7802a03a93d64d439d1d05e4d512237d8a92d4"))
		( 30, uint256("0x7578341c8b56361b7d606b332bf9168e3968551765d7fe993ca26fe16e5306ff"))
		( 40, uint256("0x1f8fe56ceee31af29765de9f208fc8e354586450b54ba294a98ba8558457e54c"))
		( 50, uint256("0x3a9b9f6586522c5457f98ba17808c17c18bac2eba55586bd5198c9619b961988"))
		( 60, uint256("0x527ed1959754453449438ac857b30b3035a1eab598daf42147e7452a435c286c"))
		( 70, uint256("0xce56c7fbf3c9e18b13392ea7e12d299e558f39e984e65140083e4d179934ab28"))
		( 80, uint256("0x0c1f5841531ef06bd67fbcae4440dbfc33d57b9f3f2b2259c41296755389efb6"))
		;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
		// return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
		// return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
				// return NULL;
        }
        return NULL;
    }
}
