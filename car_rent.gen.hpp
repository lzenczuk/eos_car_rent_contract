#pragma once
#include <eoslib/types.hpp>
#include <eoslib/message.hpp>
#include <eoslib/datastream.hpp>
#include <eoslib/raw_fwd.hpp>

using namespace carrent;

namespace eosio { namespace raw {
   template<typename Stream> inline void pack( Stream& s, const registercar& value ) {
      raw::pack(s, value.car_id);
      raw::pack(s, value.brand);
      raw::pack(s, value.model);
      raw::pack(s, value.body_type);
   }
   template<typename Stream> inline void unpack( Stream& s, registercar& value ) {
      raw::unpack(s, value.car_id);
      raw::unpack(s, value.brand);
      raw::unpack(s, value.model);
      raw::unpack(s, value.body_type);
   }
   template<typename Stream> inline void pack( Stream& s, const activate& value ) {
      raw::pack(s, value.car_id);
      raw::pack(s, value.price);
   }
   template<typename Stream> inline void unpack( Stream& s, activate& value ) {
      raw::unpack(s, value.car_id);
      raw::unpack(s, value.price);
   }
   template<typename Stream> inline void pack( Stream& s, const deactivate& value ) {
      raw::pack(s, value.car_id);
   }
   template<typename Stream> inline void unpack( Stream& s, deactivate& value ) {
      raw::unpack(s, value.car_id);
   }
   template<typename Stream> inline void pack( Stream& s, const rentcar& value ) {
      raw::pack(s, value.body_type);
   }
   template<typename Stream> inline void unpack( Stream& s, rentcar& value ) {
      raw::unpack(s, value.body_type);
   }
   template<typename Stream> inline void pack( Stream& s, const returncar& value ) {
      raw::pack(s, value.car_id);
   }
   template<typename Stream> inline void unpack( Stream& s, returncar& value ) {
      raw::unpack(s, value.car_id);
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
   void dump(const registercar& value, int tab=0) {
      print_ident(tab);print("car_id:[");prints_l(value.car_id.get_data(), value.car_id.get_size());print("]\n");
      print_ident(tab);print("brand:[");prints_l(value.brand.get_data(), value.brand.get_size());print("]\n");
      print_ident(tab);print("model:[");prints_l(value.model.get_data(), value.model.get_size());print("]\n");
      print_ident(tab);print("body_type:[");printi(uint64_t(value.body_type));print("]\n");
   }
   template<>
   registercar current_message<registercar>() {
      return current_message_ex<registercar>();
   }
   void dump(const activate& value, int tab=0) {
      print_ident(tab);print("car_id:[");prints_l(value.car_id.get_data(), value.car_id.get_size());print("]\n");
      print_ident(tab);print("price:[");printi(uint64_t(value.price));print("]\n");
   }
   template<>
   activate current_message<activate>() {
      return current_message_ex<activate>();
   }
   void dump(const deactivate& value, int tab=0) {
      print_ident(tab);print("car_id:[");prints_l(value.car_id.get_data(), value.car_id.get_size());print("]\n");
   }
   template<>
   deactivate current_message<deactivate>() {
      return current_message_ex<deactivate>();
   }
   void dump(const rentcar& value, int tab=0) {
      print_ident(tab);print("body_type:[");printi(uint64_t(value.body_type));print("]\n");
   }
   template<>
   rentcar current_message<rentcar>() {
      return current_message_ex<rentcar>();
   }
   void dump(const returncar& value, int tab=0) {
      print_ident(tab);print("car_id:[");prints_l(value.car_id.get_data(), value.car_id.get_size());print("]\n");
   }
   template<>
   returncar current_message<returncar>() {
      return current_message_ex<returncar>();
   }
} //eosio

