#pragma once

#include "common.hpp"
#include "cmd.hpp"


namespace gg::ui::terminal
{
/**
 * @brief Stores pointer to command and bool if the action was successful \n valid(), getCommand()
 */
template<typename Args>
class QuerryResult
{
public:
    QuerryResult(const int& code) : m_code(code) { }
    QuerryResult(const int& code, const std::shared_ptr<Command<Args>>& cmd) : m_code(code), m_cmd(cmd) { }

    /**
     * @brief Check if querry is valid
     */
    bool valid() const { return (bool)m_code; }
    /**
     * @brief Access the command ptr
     */
    std::shared_ptr<Command<Args>> getCommand() const { return m_cmd; }

private:
    std::shared_ptr<Command<Args>> m_cmd;
    int m_code;
};

/**
 * @brief Serves for command managing (queriyng, linking, ...) and stores notes
 */
template<typename Args>
class CommandLine
{
public:
    /**
     * @brief Construct a new Command Line object
     * 
     * @param command_list - list of commands which will be search against every time program is called
     */
    CommandLine(std::list<Command<Args>> command_list) 
    {
        for (Command cmd : command_list)
            m_cmds.emplace(cmd.name, std::make_shared<Command<Args>>(cmd));
    }

    /**
     * @brief Execute command
     * 
     * @param cmd_name - (string) name of command
     * @param args - argument string
     */
    void execute(const std::string &cmd_name, const Args &args) const
    {
        QuerryResult<Args> result = _querry(cmd_name);

        if (!result.valid())
            throw std::invalid_argument("Invalid command");

        Command cmd = *(result.getCommand());
        cmd.execute(args);
    }

private:
    /**
     * @brief Search for command in command list
     * 
     * @param cmd_name - command name
     * @return QuerryResult 
     */
    QuerryResult<Args> _querry(const std::string cmd_name) const
    {
        auto cmd = m_cmds.find(cmd_name);

        if (cmd == m_cmds.end())
            return QuerryResult<Args>(0);

        auto x = *cmd;

        return QuerryResult(1, cmd->second);
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Command<Args>>> m_cmds;
};
}
