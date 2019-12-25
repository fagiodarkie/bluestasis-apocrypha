//
// Created by apteros on 12/12/2019.
//

#include "Screen.h"

namespace engine::screen
{
    void Screen::serialisation() {
        synch("id", _id);
        synch("title", _title);
        synch("content", _text);
        synch("options", _options);
    }

    std::string Screen::title() const {
        return _title;
    }

    std::string Screen::text() const {
        return _text;
    }
    std::string Screen::id() const {
        return _id;
    }

    Screen::option_iterator Screen::firstOption() const
    {
        return _options.cbegin();
    }

    Screen::option_iterator Screen::lastOption() const
    {
        return _options.cend();
    }

    Screen::option_iterator Screen::option(const std::string & option_key) const
    {
        for (auto option = firstOption(); option != lastOption(); ++option)
            if (option->key() == option_key)
                return option;

        return lastOption();
    }

}