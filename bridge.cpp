#include <iostream>

class Device {
public:
    virtual bool isEnabled() = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual int getVolume() = 0;
    virtual void setVolume(int) = 0;
};


class TV : public Device {
public:
    TV() = default; 
    bool isEnabled() override { return _enabled; }
    void enable() override { _enabled = 1; }
    void disable() override { _enabled = 0; }
    int getVolume() override { return _volume; }
    void setVolume(int volume) override { _volume = volume; }
private:
    int _volume;
    bool _enabled;
};

class Radio : public Device {
public:
    Radio() = default;
    bool isEnabled() override { return _enabled; }
    void enable() override { _enabled = 1; }
    void disable() override { _enabled = 0; }
    int getVolume() override { return _volume; }
    void setVolume(int volume) override { _volume = volume; }
private:
    int _volume;
    bool _enabled;
};


class RemoteControl {
public:
    RemoteControl(Device *device) : _device(device) {}
    virtual void togglePower() = 0;
    virtual void volumeUp() = 0;
    virtual void volumeDown() = 0;
protected:    
    Device *_device;
};

class AdvancedRemoteControl : public RemoteControl {
public:
    AdvancedRemoteControl(Device *device) : RemoteControl(device) {}
    void togglePower() override { 
        if (_device->isEnabled()) _device->disable();
        else _device->enable();
    }
    void volumeUp() override { _device->setVolume(_device->getVolume() + 1); }
    void volumeDown() override { _device->setVolume(_device->getVolume() - 1); }
    void mute() { _device->setVolume(0); }
};

int main() {
    TV tv;
    Radio radio;
    AdvancedRemoteControl remote(&tv);
    remote.togglePower();
    std::cout << "tv is now " << tv.isEnabled() << std::endl;
    remote.volumeUp();
    std::cout << "tv's volume now is " << tv.getVolume() << std::endl;

    remote = &radio;
    remote.togglePower();
    std::cout << "radio is now " << radio.isEnabled() << std::endl;
    remote.togglePower();
    std::cout << "radio is now " << radio.isEnabled() << std::endl;

    return 0;
}