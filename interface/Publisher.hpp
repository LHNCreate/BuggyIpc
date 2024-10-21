//
// Created by leehaonan on 24-10-17.
//

#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP
#include <zmq.hpp>

#include "result.hpp"

namespace OneIpc {
    class Publisher {
    private:
        zmq::context_t _context;
        zmq::socket_t _publisher;

    public:
        explicit Publisher(uint8_t maxThreads)
            : _context(maxThreads),
              _publisher(_context, zmq::socket_type::pub) {
        }


        /**
         *
         * @param address
         * the address of ipc/tcp
         *
         * @example
         * ipc:///tmp/example
         *
         * @example
         * tcp://ip:port
         *
         */
        ara::core::Result<ara::core::unit_t,zmq::error_t> publish(const std::string &address);


        /**
         *
         * @param message
         *
         * @param flags
         * @return
         */
        ara::core::Result<size_t, zmq::error_t>
        send(const std::string &message, zmq::send_flags flags = zmq::send_flags::none);
    };
}


#endif //PUBLISHER_HPP
