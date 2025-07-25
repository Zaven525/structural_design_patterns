#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
#include <memory>

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
    std::unique_ptr<Message> message;
};

class UpperCaseDecorator : public Decorator{
    std::string getText(const std::string& message) const override { 
        std::string tmp_message = message;
        for (int i = 0; i < tmp_message.size(); i++) {
            tmp_message[i] = toupper(tmp_message[i]);
        }
    }
};

class LowerCaseDecorator : public Decorator {
    std::string getText(const std::string& message) const override {
        std::string tmp_message = message;
        for (int i =0; i < tmp_message.size(); i++) {
            tmp_message[i] = tolower(tmp_message[i]);
        }
    }
};

class EncryptedMessageDecorator : public Decorator {
public:
    EncryptedMessageDecorator(std::unordered_map<char &a, char &b>) {}
private:
    std::unordered_map ;
};


int main() {

    return 0;
}