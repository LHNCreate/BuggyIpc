//
// Created by leehaonan on 24-10-17.
//
#include <zmq.hpp>
#include <string>
#include <iostream>

int main() {
    // 创建 ZeroMQ 上下文
    zmq::context_t context(1);

    // 创建订阅者套接字
    zmq::socket_t subscriber(context, zmq::socket_type::sub);
    // 连接到发布者的 IPC 地址
    subscriber.connect("ipc:///tmp/zmq_example");

    // 订阅所有消息
    subscriber.set(zmq::sockopt::subscribe, "");

    while (true) {
        // 接收消息
        zmq::message_t zmq_message;
        subscriber.recv(zmq_message, zmq::recv_flags::none);

        // 将消息转为字符串并打印
        std::string message(static_cast<char*>(zmq_message.data()), zmq_message.size());
        std::cout << "订阅者: 接收到消息 -> " << message << std::endl;
    }
    return 0;
}
