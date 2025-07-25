#include <iostream>
#include <unordered_map>
#include <string>

class Message {
public:
    virtual std::string getText(const std::string& message) const = 0;
};

class PlainMessage : public Message{
public:
    std::string getText(const std::string& message) const override { return message; }
};

class Decorator : public Message {
protected:
    Message *message;
};

class UpperCaseDecorator : public Decorator{
    return 
};
int main() {

    return 0;
}