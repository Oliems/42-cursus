#include "Channel.hpp"
#include "NetworkManager.hpp"
#include "def.hpp"
#include "macro.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <deque>
#include <exception>

using std::deque;
using std::map;
using std::string;

void Channel::modeCmd( tSocket setter, tModeStruct modeInstruction,  bool setting ) {

    map<tSocket, tClientRights>::iterator setterIt = _clients.find( setter );

    if ( setterIt == _clients.end() ) {
        sendToFd( setter, ERR_NOTONCHANNEL( modeInstruction.setter->getNickName(), _channelName.asString() ) );
        return;
    }

    tClientRights & client = setterIt->second;

    if ( client.isOperator == false ) {
        return ( sendToFd( setter, ERR_CHANOPRIVSNEEDED( client.client->getNickName(), _channelName.asString() ) ) );
    }

    bool changes = false;

    if ( setting ) {
        modeUp( setter, modeInstruction, changes );
    } else {
        modeDown( setter, modeInstruction, changes );
    }

    if ( changes ) {
        sendMsgToAllChannelMember( RPL_CHANNELMODEIS( client.client->getNickName(), _channelName.asString(), listRights() ), setter );
        sendToFd( setter, RPL_CHANNELMODEIS( client.client->getNickName(), _channelName.asString(), listRights() ) );
    }
}

#include <iostream>

void Channel::modeUp( tSocket setter, tModeStruct modeInstruction,  bool & changes ) {

    if ( modeInstruction.settedOp ) {
        map<tSocket, tClientRights>::iterator settedIt = _clients.find( modeInstruction.settedOp->getSocket() );
        if ( settedIt == _clients.end() ) {
            sendToFd( setter, ERR_USERNOTINCHANNEL( modeInstruction.settedOp->getNickName(), _channelName.asString() ) );
        } else {
            sendMsgToAllChannelMember( ":" + _clients.find( setter )->second.client->getNickName() + " MODE " + _channelName.asString() + " +o " + settedIt->second.client->getNickName(), -1 );
            settedIt->second.isOperator = true;
            _nbOperator++;
        }
    }

    if ( modeInstruction.topic ) {
        _mode |= TOPIC_FR_OP;
        changes = true;
    }

    if ( modeInstruction.invite ) {
        _mode |= INVITE_ONLY;
        changes = true;
    }

    if ( modeInstruction.passWordOpt ) {
        if ( _mode & PASS_NEEDED ) {
            sendToFd( setter, ERR_KEYSET( _channelName.asString() ) );
        } else {
            _passWord = modeInstruction.passWord;
			std::cout << "mdp -" << modeInstruction.passWord << "-" << std::endl;
            _mode |= PASS_NEEDED;
        }
        changes = true;
    }

    if ( modeInstruction.userLimit != -1 ) {
        _mode |= LIMIT_USERS;
        if ( modeInstruction.userLimit > MAX_USER_PER_CHAN ) {
            _userLimit = MAX_USER_PER_CHAN;
        } else {
            _userLimit = modeInstruction.userLimit;
        }
        changes = true;
    }
}

void Channel::modeDown( tSocket setter, tModeStruct modeInstruction,  bool & changes ) {

    if ( modeInstruction.settedOp ) {
        map<tSocket, tClientRights>::iterator settedIt = _clients.find( modeInstruction.settedOp->getSocket() );
        if ( settedIt == _clients.end() ) {
            sendToFd( setter, ERR_USERNOTINCHANNEL( modeInstruction.settedOp->getNickName(), _channelName.asString() ) );
        } else {
            sendMsgToAllChannelMember( ":" + _clients.find( setter )->second.client->getNickName() + " MODE " + _channelName.asString() + " -o " + settedIt->second.client->getNickName(), -1 );
            settedIt->second.isOperator = false;
            _nbOperator--;
        }
    }
    if ( modeInstruction.topic ) {
        _mode &= ~TOPIC_FR_OP;
        changes = true;
    }

    if ( modeInstruction.invite ) {
        _mode &= ~INVITE_ONLY;
        changes = true;
    }

    if ( modeInstruction.passWordOpt
         && modeInstruction.passWord == _passWord
         && _mode & PASS_NEEDED ) {
        _mode &= ~PASS_NEEDED;
        changes = true;
    }

    if ( modeInstruction.userLimit != -1 ) {
        _mode &= ~LIMIT_USERS;
        changes = true;
    }
}

string Channel::listRights( void ) const {
    string ret( "+" );

    if ( _mode & INVITE_ONLY )
        ret += "i";
    if ( _mode & TOPIC_FR_OP )
        ret += "t";
    if ( _mode & PASS_NEEDED )
        ret += "k";
    if ( _mode & LIMIT_USERS )
        ret += "l";

    if ( ret.size() == 1 )
        return ( ":channel mode by default." );
    return ( ret );
}
