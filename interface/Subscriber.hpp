//
// Created by leehaonan on 24-10-17.
//

#ifndef SUBSCRIBER_HPP
#define SUBSCRIBER_HPP
#include <zmq.hpp>
#include <result.hpp>
namespace OneIpc {
    class Subscriber {
    private:
        zmq::context_t _context;
        zmq::socket_t _subscriber;

    public:
        Subscriber(uint8_t maxThreads)
            : _context(maxThreads),
              _subscriber(_context, zmq::socket_type::sub) {
        }

        ara::core::Result<ara::core::unit_t,zmq::error_t> subscribe(const std::string &address);
    };
}


#endif //SUBSCRIBER_HPP
