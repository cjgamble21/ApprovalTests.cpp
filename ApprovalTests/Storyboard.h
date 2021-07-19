#pragma once

#include <iosfwd>
#include <sstream>
#include <functional>

namespace ApprovalTests
{
    class StoryBoard
    {
    private:
        std::stringstream output_;
        int frameCount_ = 0;
        bool addNewLineBeforeNextFrame_ = false;

    public:
        StoryBoard& addDescription(const std::string& description);

        StoryBoard& addDescriptionWithData(const std::string& description,
                                           const std::string& data);

        StoryBoard& addFrame(const std::string& frame);

        StoryBoard& addFrame(const std::string& title, const std::string& frame);

        StoryBoard& addFrames(int numberOfFrames,
                              const std::function<std::string(int)>& function);

        friend std::ostream& operator<<(std::ostream& os, const StoryBoard& board);
    };
}