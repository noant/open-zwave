#include "command_classes/CommandClass.h"

namespace OpenZWave
{
	/** Implements COMMAND_CLASS_SIMPLE_AV_CONTROL (0x94), a Z-Wave device command class. */
	class AVSimple : public CommandClass
	{
	public:
		static CommandClass* Create(uint32 const _homeId, uint8 const _nodeId) { return new AVSimple(_homeId, _nodeId); }
		virtual ~AVSimple() {}

		static uint8 const StaticGetCommandClassId() { return 0x94; }
		static string const StaticGetCommandClassName() { return "COMMAND_CLASS_SIMPLE_AV_CONTROL"; }

		// From CommandClass
		virtual uint8 const GetCommandClassId()const { return StaticGetCommandClassId(); }
		virtual string const GetCommandClassName()const { return StaticGetCommandClassName(); }
		virtual bool HandleMsg(uint8 const* _data, uint32 const _length, uint32 const _instance = 1);
		virtual bool SetValue(Value const& _value);

	protected:
		virtual void CreateVars(uint8 const _instance);
		
	private:
		AVSimple(uint32 const _homeId, uint8 const _nodeId) : CommandClass(_homeId, _nodeId) {}
		uint8 m_sequence;
	};

	class AVSimpleCommand
	{
	public: 
		AVSimpleCommand(uint16 const _code, string _name, string _description, uint16 const _version);
		uint16 GetCode();
		string GetName();
		string GetDescription();
		uint16 GetVersion();

		static vector<AVSimpleCommand> GetCommands();

	private:
		uint16 m_code;
		string m_name;
		string m_description;
		uint16 m_version;

		static vector<AVSimpleCommand> m_commands;
	};

} // namespace OpenZWave