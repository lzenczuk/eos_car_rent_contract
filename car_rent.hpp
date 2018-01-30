/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eoslib/string.hpp>

namespace carrent {

    // @abi action registercar
    struct registercar {
        eosio::string car_id;
        eosio::string brand;
        eosio::string model;
        uint8_t body_type;
    };

// @abi action activate
    struct activate {
        eosio::string car_id;
        uint64_t price;
    };

// @abi action deactivate
    struct deactivate {
        eosio::string car_id;
    };

// @abi action rentcar
    struct rentcar {
        uint8_t body_type;
    };

// @abi action returncar
    struct returncar {
        eosio::string car_id;
    };

}
