//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARhost1ULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package prova1.pkgprova;

simple Host
{
    parameters:
        @display("i=block/routing_vs,yellow;is=vs");
        @display("t=CIAO");
        @display("p=50,50");
    gates:
        inout gate[];
}

simple Hust
{
    parameters:
        @display("i=block/process_vs,blue");
        @display("t=Come Stai ?");
        @display("p=10,10");
    gates:
        inout gate[];
}

//
// Two instances (host1 and host2) of Host connected both ways.
// host1 and host2 will pass messages to one another.
//
network Prova1Net
{
    parameters:
        @display("bgb=431,298");
        @display("bgg=10");

    types:
        channel Channel extends ned.DelayChannel
        {
            delay = 100ms;
        }

    submodules:
        host1: Host;
        host2: Hust;
    connections:
        host1.gate++ <--> Channel <--> host2.gate++;
}
