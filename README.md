Implementation of simple timeout event handler. The idea is that the user
subscribes to two events, 10s and 20s timeout event. Two independent threads are
created for these two events that sleep for 10s and 20s, after which the main
thread is informed of creation of these events and produces output:

Subscription to TimeoutEvent started at: Thu Sep  9 13:54:48 2021

10 sec timeout event Thu Sep  9 13:54:58 2021

20 sec timeout event Thu Sep  9 13:55:08 2021
