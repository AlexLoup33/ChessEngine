#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include <string>
#include <vector>

#pragma once

class EngineConfiguration{
    public:
        EngineConfiguration(const std::string& path_file);

        /**
         * @brief loading the engine config from a file.
         * @param path : the path of the file who contain the config
         * @return Return an int value for informing user that the load is ok or not
         */
        int loadEngineConfiguration(const std::string& path_file);

        /**
         * @brief saving the engine config into a file.
         * @param path : the path of the file where we will store the config.
         * @return Return an int value for informing user that the save is ok or not.
         */
        int saveEngineConfiguration(const std::string& path_file);
    
    private:
};


class GameConfiguration{
    public:
        GameConfiguration(const std::string& path_file);

        int loadGameConfiguration(const std::string& path_file);

        int saveGameConfiguration(const std::string& path_file);

    private:
};


#endif // __CONFIG_HPP__