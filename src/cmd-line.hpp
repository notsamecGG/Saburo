#pragma once

#include "common.hpp"
#include "cmd.hpp"
#include "note.hpp"


class QuerryResult
{
public:
    QuerryResult(int code) : m_code(code) { }
    QuerryResult(int code, std::weak_ptr<Command> cmd) : m_code(code), m_cmd(cmd) { }

    bool valid() { return (bool)m_code; }
    std::weak_ptr<Command> getCommand() { return m_cmd; }

private:
    std::weak_ptr<Command> m_cmd;
    int m_code;
};

class CommandLine
{
public:
    CommandLine(std::list<Command> command_list) 
    {
        for (Command cmd : command_list)
            m_cmds.emplace(cmd.name, std::make_shared<Command>(cmd));
    }

    void execute(const std::string cmd_name, const std::any args) const
    {
        QuerryResult result = _querry(cmd_name);

        if (!result.valid())
            throw "Invalid command";

        Command cmd = *result.getCommand().lock();
        cmd.execute(args, std::make_shared<std::vector<Note>>(m_notes));
    }

    std::unique_ptr<std::vector<Note>> notes() { return std::make_unique<std::vector<Note>>(m_notes); }

private:
    QuerryResult _querry(const std::string cmd_name) const
    {
        auto cmd = m_cmds.find(cmd_name);

        if (cmd == m_cmds.end())
            return QuerryResult(0);

        return QuerryResult(1, std::make_shared<Command>(*cmd));
    }

private:
    std::vector<Note> m_notes;
    std::unordered_map<std::string, std::weak_ptr<Command>> m_cmds;
};
