/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eoslib/eos.hpp>

#include "car_rent.hpp"
#include "car_rent.gen.hpp"

using namespace carrent;

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

        //if(code==N(carrent)){
        if(code==eosio::string_to_name("carrent")){
            if(action==N(registercar)){
                auto acm = eosio::current_message<registercar>();

                eosio::print("Add car message");
                eosio::dump(acm);

            }else if(action==N(activate)){
                auto afr = eosio::current_message<activate>();

                eosio::print("Activate rent message");
                eosio::dump(afr);

            }else if(action==N(deactivate)){
                auto wfr = eosio::current_message<deactivate>();

                eosio::print("Withdraw from rent message");
                eosio::dump(wfr);

            }else if(action==N(rentcar)){
                auto rc = eosio::current_message<rentcar>();

                eosio::print("Rent car message");
                eosio::dump(rc);

            }else if(action==N(returncar)){
                auto rc = eosio::current_message<returncar>();

                eosio::print("Return car message");
                eosio::dump(rc);

            }
        }
    }

} // extern "C"
