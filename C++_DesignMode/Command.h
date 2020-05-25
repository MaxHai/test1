
#pragma once

#include <iostream>
#include <vector>

class Light
{
public:
	Light();
	~Light();

public:
	void On()
	{
		std::cout << "灯亮了" << std::endl;
	}

	void Off()
	{
		std::cout << "灯灭了" << std::endl;
	}

private:

};

Light::Light()
{
}

Light::~Light()
{
}

/* 抽象出一个类，专门记录这个动作 */

class Command
{
protected:
	Command();
	~Command();

public:
	virtual void Execute() = 0;
	virtual void Undo() = 0;

private:

};

Command::Command()
{
}

Command::~Command()
{
}

/* 具体的命令对象：就是用来开灯的 
 * 持有一个Receiver的实例，让这个Receiver自己去处理自己的运行 */
/* 突出一个特点：我们问题聚焦的是如何规划“请求这个动作”
 * 而这个动作的真正执行，是通过我们将证书设备组合进入这个
  * ConcreteCommand里面来的(LightOnCommand) */
class LightOnCommand : public Command
{
public:
	LightOnCommand(Light* pLight):m_pLight(pLight){}
	~LightOnCommand();

public:
	virtual void Execute()
	{
		m_pLight->On();
	}

	void Undo()
	{
		m_pLight->Off();
	}

private:
	Light* m_pLight;
};

LightOnCommand::~LightOnCommand()
{
}

class LightOffCommand : public Command
{
public:
	LightOffCommand(Light* pLight):m_pLight(pLight){}
	~LightOffCommand();

public:
	virtual void Execute()
	{
		m_pLight->Off();
	}

	void Undo()
	{
		m_pLight->On();
	}

private:
	Light* m_pLight;
};

LightOffCommand::~LightOffCommand()
{
}

class NoCommand : public Command
{
public:
	NoCommand();
	~NoCommand();

public:
	virtual void Execute() {}
	virtual void Undo() {}

private:

};

NoCommand::NoCommand()
{
}

NoCommand::~NoCommand()
{
}

/* 宏命令 */
class MacroCommand : public Command
{
public:
	MacroCommand(std::vector<Command*> Commands):m_Commands(Commands){}
	~MacroCommand();

public:
	virtual void Execute()
	{
		for (std::vector<Command*>::iterator iter = m_Commands.begin(); iter != m_Commands.end(); iter++)
		{
			(*iter)->Execute();
		}
	}

	virtual void Undo()
	{
		for (std::vector<Command*>::iterator iter = m_Commands.begin(); iter != m_Commands.end(); iter++)
		{
			(*iter)->Undo();
		}
	}

private:
	std::vector<Command*> m_Commands;
};

MacroCommand::~MacroCommand()
{
}

class Sound
{
public:
	Sound();
	~Sound();

public:
	void On()
	{
		std::cout << "声音设备打开了" << std::endl;
	}

	void Off()
	{
		std::cout << "声音设备关闭了" << std::endl;
	}

private:

};

Sound::Sound()
{
}

Sound::~Sound()
{
}

class SoundOnCommand : public Command
{
public:
	SoundOnCommand(Sound* pSound):m_pSound(pSound){}
	~SoundOnCommand();

public:
	virtual void Execute()
	{
		m_pSound->Off();
	}

	void Undo()
	{
		m_pSound->On();
	}

private:
	Sound* m_pSound;
};

SoundOnCommand::~SoundOnCommand()
{
}

/* invoker可以出发任意的命令对象，invoker可以发任何命令 */
/*
class SimpleRemoteControl
{
public:
	SimpleRemoteControl();
	~SimpleRemoteControl();

public:
	void SetCommand(Command* pCommand)
	{
		m_pCommand = pCommand;

		m_pUndoCommand = new NoCommand();
	}

	// 当前的这个命令对象，既可以关闭，也可以打开 
	void OnButtonWasPushed()
	{
		m_pCommand->Execute();
		m_pUndoCommand = m_pCommand;
	}

	void OffButtonWasPushed()
	{
		m_pCommand->Execute();
		m_pUndoCommand = m_pCommand;
	}

	void UndoButtonWasPushed()
	{
		m_pUndoCommand->Undo();
	}

private:
	Command* m_pCommand;
	Command* m_pUndoCommand;
};
*/

/* 能够批量执行命令的loader */
class SimpleRemoteControlLoader
{
public:
	void SetCommand(Command* pCommand)
	{
		m_pCommand = pCommand;
	}

	void OnCommandStart()
	{
		m_pCommand->Execute();
	}


private:
	Command* m_pCommand;
};

void CommandModeTest()
{
	/*
	SimpleRemoteControl* pRemote = new SimpleRemoteControl();
	Light* pLight = new Light();
	LightOnCommand* pLightOn = new LightOnCommand(pLight);
	pRemote->SetCommand(pLightOn);
	pRemote->OnButtonWasPushed();
	pRemote->UndoButtonWasPushed();
	pRemote->OffButtonWasPushed();
	pRemote->UndoButtonWasPushed();
	*/


	/* 宏命令演示 */
	std::cout << "---------------宏命令演示---------------" << std::endl;
	Light* pLight = new Light();
	LightOnCommand* pLightOn = new LightOnCommand(pLight);
	Sound* pSound = new Sound();
	SoundOnCommand* pSoundOn = new SoundOnCommand(pSound);
	std::vector<Command*> myCommands;
	myCommands.push_back(pLightOn);
	myCommands.push_back(pSoundOn);
	MacroCommand* pMacroCommands = new MacroCommand(myCommands);
	SimpleRemoteControlLoader* pRemoteCommands = new SimpleRemoteControlLoader();
	pRemoteCommands->SetCommand(pMacroCommands);
	pRemoteCommands->OnCommandStart();
	//pRemote->SetCommand(pMacroCommands);现在我们需要批量的执行宏命令，新增一个RemoteInvoker的宏命令执行方法

	/* 灯亮了被invoker：SimepleRemote隐藏起来了，（封装了设备）
	 * 接下来，只要关注invoker，并且invoker进行控制，就能把一系列的“动作”记录下来*/

}