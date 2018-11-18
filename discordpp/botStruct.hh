//
// Created by Aidan on 6/21/2018.
//

#ifndef EXAMPLE_BOT_BOTREQUIRED_HH
#define EXAMPLE_BOT_BOTREQUIRED_HH

#include <iostream>

#include <boost/asio.hpp>

#include <nlohmann/json.hpp>

namespace discordpp {
    using json = nlohmann::json;

    struct ratelimit{
        int millis;
    };

    class BotStruct {
    public:
        virtual json call(std::string requestType, std::string targetURL, json body) = 0;

        void run(){
            bool ready = true;
            for(auto module: needInit){
                if(module.second){
                    std::cerr << "Forgot to initialize: " << module.first << '\n';
                    ready = false;
                }
            }
            if(ready) {
                aioc->run();
            }
        }

    protected:
        std::map<std::string, bool> needInit;
        unsigned int apiVersion = 6;
        std::shared_ptr<boost::asio::io_context> aioc;
        std::string token;
    };
}

#endif //EXAMPLE_BOT_BOTREQUIRED_HH
