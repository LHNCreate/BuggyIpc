//
// Created by leehaonan on 24-10-17.
//
#include <zmq.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <OneIpc.hpp>
int main() {
    // // 创建 ZeroMQ 上下文
    // zmq::context_t context(1);
    //
    // // 创建发布者套接字
    // zmq::socket_t publisher(context, zmq::socket_type::pub);
    // // 绑定到 IPC 协议的地址
    // publisher.bind("ipc:///tmp/zmq_example");
    //
    // while (true) {
    //     // 创建消息
    //     std::string message = "Hello from Publisher!";
    //     zmq::message_t zmq_message(message.size());
    //     memcpy(zmq_message.data(), message.c_str(), message.size());
    //
    //     // 发送消息
    //     auto reuslt = publisher.send(zmq_message, zmq::send_flags::none);
    //     std::cout <<"bytes: " << reuslt.value() << std::endl;
    //     std::cout << "发布者: 发送消息 -> " << message << std::endl;
    //
    //     // 模拟延迟
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    // }
    OneIpc::Publisher pub(1);
    auto result = pub.publish("ipc:///tmp/zmq_example");
    if (result.is_ok()) {
        std::cout <<"bind ok" << std::endl;
    }else {
        std::cerr << result.unwrap_err().what() << std::endl;
    }
    while (true) {
        // 创建消息
        std::string message = "Hello from Publisher!";
        auto result = pub.send(message);

        if(result.is_ok()) {
            auto bytes = result.unwrap();
            std::cout << bytes << std::endl;
        }

        std::cout << "发布者: 发送消息 -> " << message << std::endl;

        // 模拟延迟
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
