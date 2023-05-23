#include <iostream>
#include <string>
/*Task: Electronic Devices Hierarchy
with Interfaces Darius*/

class ElectronicDevice
{
protected:
    std::string brand;
    std::string model;
    std::string power_consumption;

public:
    ElectronicDevice(const std::string &brand, const std::string &model, const std::string &power_consumption)
        : brand(brand), model(model),power_consumption(power_consumption) {}

    virtual void displayDevice() const
    {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "power_consumption: " << power_consumption << std::endl;
    }
};

class Phone : public ElectronicDevice
{
    public:
    Phone(const std::string &brand, const std::string &model, const std::string &power_consumption)
        : ElectronicDevice(brand,model,power_consumption) {}

    void displayDevice() const override {
        std::cout << "Phone" << std::endl;
        ElectronicDevice::displayDevice();
    }
};

class Tablet : public ElectronicDevice
{
    public:
    Tablet(const std::string &brand, const std::string &model, const std::string &power_consumption)
        : ElectronicDevice(brand,model,power_consumption) {}

    void displayDevice() const override {
        std::cout << "Tablet" << std::endl;
        ElectronicDevice::displayDevice();
    }
};

class Laptop : public ElectronicDevice
{
    public:
    Laptop(const std::string &brand, const std::string &model, const std::string &power_consumption)
        : ElectronicDevice(brand,model,power_consumption) {}

    void displayDevice() const override {
        std::cout << "Laptop" << std::endl;
        ElectronicDevice::displayDevice();
    }
};

class Interfaces
{
protected:
    std::string touchscreen_interface;
    std::string voice_command_interface;
public:
    Interfaces(const std::string &touchscreen_interface, const std::string &voice_command_interface)
        : touchscreen_interface(touchscreen_interface), voice_command_interface(voice_command_interface){}

    virtual void displayInterface() const
    {
        std::cout << "touchscreen_interface: " << touchscreen_interface << std::endl;
        std::cout << "voice_command_interface: " << voice_command_interface << std::endl;
    }
};

class DeviceInterfaces : public ElectronicDevice, public Interfaces
{
public:
    DeviceInterfaces(const std::string &Phone , const std::string &Tablet,
                    const std::string &Laptop, const std::string &touchscreen_interface,
                    const std::string &voice_command_interface)
        : ElectronicDevice(Phone, Tablet, Laptop), Interfaces(touchscreen_interface, voice_command_interface) {}

    void displayDevice() const override
    {
        std::cout << "Device interface" << std::endl;
        ElectronicDevice::displayDevice();
        displayInterface();
    }
};

int main()
{
    Phone NewPhone("Nokia", "3310", "Low battery consumption");
    Tablet NewTablet("Ipad", "Txc", "Medium battery consumption");
    Laptop NewLaptop("Lenovo", "Legion", "HIgh battery consumption");
    DeviceInterfaces DeviceInterfaces1 ("Nokia", "3310",
                                    "Low battery consumption", "Not-available","Not-available");

    NewPhone.displayDevice();
    std::cout << std::endl;

    NewTablet.displayDevice();
    std::cout << std::endl;

    NewLaptop.displayDevice();
    std::cout << std::endl;

    DeviceInterfaces1.displayDevice();

    return 0;
}