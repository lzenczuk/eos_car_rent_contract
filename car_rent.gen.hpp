#pragma once
#include <eoslib/types.hpp>
#include <eoslib/message.hpp>
#include <eoslib/datastream.hpp>
#include <eoslib/raw_fwd.hpp>

using namespace car_rent;

namespace eosio { namespace raw {
   template<typename Stream> inline void pack( Stream& s, const add_car_msg& value ) {
      raw::pack(s, value.car_id);
      raw::pack(s, value.brand);
      raw::pack(s, value.model);
      raw::pack(s, value.body_type);
   }
   template<typename Stream> inline void unpack( Stream& s, add_car_msg& value ) {
      raw::unpack(s, value.car_id);
      raw::unpack(s, value.brand);
      raw::unpack(s, value.model);
      raw::unpack(s, value.body_type);
   }
   template<typename Stream> inline void pack( Stream& s, const activate_rent_msg& value ) {
      raw::pack(s, value.car_id);
      raw::pack(s, value.price);
   }
   template<typename Stream> inline void unpack( Stream& s, activate_rent_msg& value ) {
      raw::unpack(s, value.car_id);
      raw::unpack(s, value.price);
   }
   template<typename Stream> inline void pack( Stream& s, const deactivate_rent_msg& value ) {
      raw::pack(s, value.car_id);
   }
   template<typename Stream> inline void unpack( Stream& s, deactivate_rent_msg& value ) {
      raw::unpack(s, value.car_id);
   }
   template<typename Stream> inline void pack( Stream& s, const rent_car_msg& value ) {
      raw::pack(s, value.body_type);
   }
   template<typename Stream> inline void unpack( Stream& s, rent_car_msg& value ) {
      raw::unpack(s, value.body_type);
   }
   template<typename Stream> inline void pack( Stream& s, const return_car_msg& value ) {
   }
   template<typename Stream> inline void unpack( Stream& s, return_car_msg& value ) {
   }
} }

#include <eoslib/raw.hpp>
namespace eosio {
   void print_ident(int n){while(n-->0){print("  ");}};
   template<typename Type>
   Type current_message_ex() {
      uint32_t size = message_size();
      char* data = (char *)eosio::malloc(size);
      assert(data && read_message(data, size) == size, "error reading message");
      Type value;
      eosio::raw::unpack(data, size, value);
      eosio::free(data);
      return value;
   }
   void dump(const add_car_msg& value, int tab=0) {
      print_ident(tab);print("car_id:[");prints_l(value.car_id.get_data(), value.car_id.get_size());print("]\n");
      print_ident(tab);print("brand:[");prints_l(value.brand.get_data(), value.brand.get_size());print("]\n");
      print_ident(tab);print("model:[");prints_l(value.model.get_data(), value.model.get_size());print("]\n");
      print_ident(tab);print("body_type:[");printi(uint64_t(value.body_type));print("]\n");
   }
   template<>
   add_car_msg current_message<add_car_msg>() {
      return current_message_ex<add_car_msg>();
   }
   void dump(const activate_rent_msg& value, int tab=0) {
      print_ident(tab);print("car_id:[");prints_l(value.car_id.get_data(), value.car_id.get_size());print("]\n");
      print_ident(tab);print("price:[");printi(uint64_t(value.price));print("]\n");
   }
   template<>
   activate_rent_msg current_message<activate_rent_msg>() {
      return current_message_ex<activate_rent_msg>();
   }
   void dump(const deactivate_rent_msg& value, int tab=0) {
      print_ident(tab);print("car_id:[");prints_l(value.car_id.get_data(), value.car_id.get_size());print("]\n");
   }
   template<>
   deactivate_rent_msg current_message<deactivate_rent_msg>() {
      return current_message_ex<deactivate_rent_msg>();
   }
   void dump(const rent_car_msg& value, int tab=0) {
      print_ident(tab);print("body_type:[");printi(uint64_t(value.body_type));print("]\n");
   }
   template<>
   rent_car_msg current_message<rent_car_msg>() {
      return current_message_ex<rent_car_msg>();
   }
   void dump(const return_car_msg& value, int tab=0) {
   }
   template<>
   return_car_msg current_message<return_car_msg>() {
      return current_message_ex<return_car_msg>();
   }
} //eosio

