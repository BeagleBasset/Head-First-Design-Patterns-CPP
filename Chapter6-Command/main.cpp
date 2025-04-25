#include "RemoteControl.hpp"
#include "Light.hpp"
#include "LightOnCommand.hpp"
#include "LightOffCommand.hpp"
#include "TV.hpp"
#include "TVOffCommand.hpp"
#include "TVOnCommand.hpp"
#include "Stereo.hpp"
#include "StereoOffCommand.hpp"
#include "StereoOnCommand.hpp"
#include "Hottub.hpp"
#include "HottubeOnCommand.hpp"
#include "HottubOffCommand.hpp"
#include "MacroCommand.hpp"
#include "CeilingFan.hpp"
#include "CeilingFanHighCommand.hpp"
#include "CeilingFanOffCommand.hpp"
#include<iostream>
#include<vector>
#include<memory>

int main()
{
    RemoteControl remoteControl = RemoteControl();

    Light light = Light("Living Room");
    TV tv = TV("Living Room");
    Stereo stereo = Stereo("Living Room");
    Hottub hottub = Hottub();
    CeilingFan ceilingFan = CeilingFan("Kitchen");

    std::shared_ptr<Command> lightOn = std::make_shared<LightOnCommand>(light);
    std::shared_ptr<Command> stereoOn = std::make_shared<StereoOnCommand>(stereo);
    std::shared_ptr<Command> tvOn = std::make_shared<TVOnCommand>(tv);
    std::shared_ptr<Command> hottubOn = std::make_shared<HottubOnCommand>(hottub);
    std::shared_ptr<Command> ceilingFanHigh = std::make_shared<CeilingFanHighCommand>(ceilingFan);


    std::shared_ptr<Command> lightOff = std::make_shared<LightOffCommand>(light);
    std::shared_ptr<Command> stereoOff = std::make_shared<StereoOffCommand>(stereo);
    std::shared_ptr<Command> tvOff = std::make_shared<TVOffCommand>(tv);
    std::shared_ptr<Command> hottubOff = std::make_shared<HottubOffCommand>(hottub);
    std::shared_ptr<Command> ceilingFanOff = std::make_shared<CeilingFanOffCommand>(ceilingFan);


    std::vector<std::shared_ptr<Command>> partyOn = { lightOn, stereoOn, tvOn, hottubOn };
    std::vector<std::shared_ptr<Command>> partyOff = { lightOff, stereoOff, tvOff, hottubOff };

    auto partyOnMacro = std::make_shared<MacroCommand>(partyOn);
    auto partyOffMacro = std::make_shared<MacroCommand>(partyOff);

    remoteControl.setCommand(0, partyOnMacro, partyOffMacro);
    remoteControl.setCommand(1, ceilingFanHigh, ceilingFanOff);

    std::cout << remoteControl.toString() << std::endl;

    std::cout << "--- Pushing Macro On---" << std::endl;
    remoteControl.onButtonWasPushed(0);
    std::cout << "--- Pushing Macro Off---" << std::endl;
    remoteControl.offButtonWasPushed(0);
    std::cout << "--- Pushing Undo---" << std::endl;
    remoteControl.undoButtonWasPushed();

    std::cout << "--- Pushing Ceiling Fan High---" << std::endl;
    remoteControl.onButtonWasPushed(1);
    std::cout << "--- Pushing Ceiling Fan Off---" << std::endl;
    remoteControl.offButtonWasPushed(1);
    std::cout << "--- Pushing Undo---" << std::endl;
    remoteControl.undoButtonWasPushed();

    return 0;
}