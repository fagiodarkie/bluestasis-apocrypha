//
// Created by apteros on 12/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_OPTION_H
#define BLUESTASIS_APOCRYPHA_OPTION_H

#include "../../thirdparty/serialisable/serialisable.hpp"
#include <string>

namespace engine::option
{
    class Option : public Serialisable {
    public:
        virtual void serialisation() override;

        std::string key() const;
        std::string text() const;
        std::string endScreen() const;

    protected:
        std::string _option_text, _end_screen_id, _option_key;
    };
}


#endif //BLUESTASIS_APOCRYPHA_OPTION_H
