//
// Created by leehaonan on 24-10-17.
//
#include <Publisher.hpp>

#include "result.hpp"


ara::core::Result<ara::core::unit_t, zmq::error_t> OneIpc::Publisher::publish(const std::string &address) {
    try {
        _publisher.bind(address);
    } catch (const zmq::error_t &e) {
        // log and trace
        return ara::core::Err<zmq::error_t>(e);
    }
    //unit 为返回值void的tag。不可直接返回void
    return ara::core::Ok(ara::core::unit);
}

ara::core::Result<size_t, zmq::error_t> OneIpc::Publisher::send(const std::string &message,
                                                                   zmq::send_flags flags) {
    try {
        // zmq::message_t zmq_message(message.size());
        // memcpy(zmq_message.data(), message.data(), message.size());
        auto result = _publisher.send(zmq::buffer(message), flags);
        if (result.has_value()) {
            return ara::core::Ok<size_t>(result.value());
        }
    } catch (const zmq::error_t &e) {
        return ara::core::Err<zmq::error_t>(e);
    }
    // nullopt
    return ara::core::Ok<size_t>(0);
}
