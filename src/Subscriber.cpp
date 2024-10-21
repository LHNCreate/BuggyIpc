//
// Created by leehaonan on 24-10-17.
//
#include <Subscriber.hpp>


ara::core::Result<ara::core::unit_t,zmq::error_t> OneIpc::Subscriber::subscribe(const std::string &address) {
    try {
        _subscriber.connect(address);
        return ara::core::Ok(ara::core::unit);
    } catch (const zmq::error_t &e) {
        // log and trace
        return ara::core::Err(e);
    }
}
