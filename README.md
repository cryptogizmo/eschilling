## Schillingcoin [SCHILLING]

## What is SchillingCoin?
Schillingcoin is like Bitcoin, but based on Litecoin. http://www.eschilling.org

## License
SchillingCoin is released under the terms of the MIT license. See [COPYING](COPYING) for more information or see http://opensource.org/licenses/MIT.

## Development and contributions
Developers work in their own trees, then submit pull requests when they think their feature or bug fix is ready.

## Total SCHILLING coins

The total number of SCHILLING coins will be 100,000,000 SCHILLING coins.

## Block Time

90 Seconds

## Difficulty Retarget Time

2 hours

## Mining

You don’t need expensive mining equipment that uses lots of electricity. Just download your wallet and start mining using your computers CPU processing power.

## Rewards

Block 1 - 90,000 : 2 SCHILLING Reward
Block 90,001 - 200,000 : 2-9 SCHILLING Reward
Block 200,001 - 300,000 : 2-19 SCHILLING Reward
Block 300,001 - 400,000 : 2-29 SCHILLING Reward
Block 400,001 - 500,000 : 2-39 SCHILLING Reward
Block 500,001 - 600,000 : 2-49 SCHILLING Reward
Block 600,001 - 700,000 : 2-39 SCHILLING Reward
Block 700,001 - 800,000 : 2-29 SCHILLING Reward
Block 800,001+ : 19 SCHILLING Reward

## Make schillingcoind

    sudo apt-get install build-essential \
                         libssl-dev \
                         libdb5.1++-dev \
                         libboost-all-dev \
                         libqrencode-dev \
                         libminiupnpc-dev

    cd src/
    make -f makefile.unix USE_UPNP=1 USE_IPV6=1 USE_QRCODE=1

## Ports
RPC 22888
P2P 22999