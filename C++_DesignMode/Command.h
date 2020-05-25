
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
		std::cout << "������" << std::endl;
	}

	void Off()
	{
		std::cout << "������" << std::endl;
	}

private:

};

Light::Light()
{
}

Light::~Light()
{
}

/* �����һ���࣬ר�ż�¼������� */

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

/* �����������󣺾����������Ƶ� 
 * ����һ��Receiver��ʵ���������Receiver�Լ�ȥ�����Լ������� */
/* ͻ��һ���ص㣺��������۽�������ι滮���������������
 * ���������������ִ�У���ͨ�����ǽ�֤���豸��Ͻ������
  * ConcreteCommand��������(LightOnCommand) */
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

/* ������ */
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
		std::cout << "�����豸����" << std::endl;
	}

	void Off()
	{
		std::cout << "�����豸�ر���" << std::endl;
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

/* invoker���Գ���������������invoker���Է��κ����� */
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

	// ��ǰ�����������󣬼ȿ��Թرգ�Ҳ���Դ� 
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

/* �ܹ�����ִ�������loader */
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


	/* ��������ʾ */
	std::cout << "---------------��������ʾ---------------" << std::endl;
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
	//pRemote->SetCommand(pMacroCommands);����������Ҫ������ִ�к��������һ��RemoteInvoker�ĺ�����ִ�з���

	/* �����˱�invoker��SimepleRemote���������ˣ�����װ���豸��
	 * ��������ֻҪ��עinvoker������invoker���п��ƣ����ܰ�һϵ�еġ���������¼����*/

}