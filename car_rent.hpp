/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eoslib/string.hpp>

namespace car_rent {

    // @abi action register
    struct add_car_msg {
        eosio::string car_id;
        eosio::string brand;
        eosio::string model;
        uint8_t body_type;
    };

// @abi action activate
    struct activate_rent_msg {
        eosio::string car_id;
        uint64_t price;
    };

// @abi action deactivate
    struct deactivate_rent_msg {
        eosio::string car_id;
    };

// @abi action rent
    struct rent_car_msg {
        uint8_t body_type;
    };

// @abi action return
    struct return_car_msg{};

}
