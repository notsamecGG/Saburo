#pragma once

#include "common.hpp"
#include "cmd.hpp"


class QuerryResult
{
public:
    QuerryResult(const int& code) : m_code(code) { }
    QuerryResult(const int& code, const std::shared_ptr<Command>& cmd) : m_code(code), m_cmd(cmd) { }

    bool valid() const { return (bool)m_code; }
    std::shared_ptr<Command> getCommand() const { return m_cmd; }

private:
    std::shared_ptr<Command> m_cmd;
    int m_code;
};

class CommandLine
{
public:
    CommandLine(std::list<Command> command_list) 
    {
        m_notes = std::make_unique<std::vector<Note>>();

        for (Command cmd : command_list)
            m_cmds.emplace(cmd.name, std::make_shared<Command>(cmd));
    }

    void execute(const std::string &cmd_name, const std::string &args) const
    {
        QuerryResult result = _querry(cmd_name);

        if (!result.valid())
            throw "Invalid command";

        Command cmd = *(result.getCommand());
        cmd.execute(args, m_notes.get());
    }

    auto notes() { return m_notes.get(); }

private:
    QuerryResult _querry(const std::string cmd_name) const
    {
        auto cmd = m_cmds.find(cmd_name);

        if (cmd == m_cmds.end())
            return QuerryResult(0);

        auto x = *cmd;

        return QuerryResult(1, cmd->second);
    }

private:
    std::unique_ptr<std::vector<Note>> m_notes;
    std::unordered_map<std::string, std::shared_ptr<Command>> m_cmds;
};
