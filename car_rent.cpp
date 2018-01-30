/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eoslib/eos.hpp>

#include "car_rent.hpp"
#include "car_rent.gen.hpp"

using namespace car_rent;

/**
 *  The init() and apply() methods must have C calling convention so that the blockchain can lookup and
 *  call these methods.
 */
extern "C" {

    /**
     *  This method is called once when the contract is published or updated.
     */
    void init()  {
       eosio::print( "Init car rent contract\n" );
    }

    /// The apply method implements the dispatch of events to this contract
    void apply( uint64_t code, uint64_t action ) {
       eosio::print( "Receive message: ", eosio::name(code), "->", eosio::name(action), "\n" );

        if(code==N(car_rent)){
            if(action==N(add_car_msg)){
                auto acm = eosio::current_message<add_car_msg>();

                eosio::print("Add car message");
                eosio::dump(acm);

            }else if(action==N(acivate_for_rent_msg)){
                auto afr = eosio::current_message<activate_rent_msg>();

                eosio::print("Activate rent message");
                eosio::dump(afr);

            }else if(action==N(withdraw_from_rent_msg)){
                auto wfr = eosio::current_message<deactivate_rent_msg>();

                eosio::print("Withdraw from rent message");
                eosio::dump(wfr);

            }else if(action==N(rent_car_msg)){
                auto rc = eosio::current_message<rent_car_msg>();

                eosio::print("Rent car message");
                eosio::dump(rc);

            }else if(action==N(return_car_msg)){
                auto rc = eosio::current_message<return_car_msg>();

                eosio::print("Return car message");
                eosio::dump(rc);

            }
        }
    }

} // extern "C"
