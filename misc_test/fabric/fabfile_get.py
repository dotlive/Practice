from fabric.api import *
from fabric.colors import *
from fabric.context_managers import *

env.hosts=['192.168.115.167']
env.password='amythpcel'

def task1():
	print(green("I'm 167 test directory"))
	local('ls -l ~/test')

def task2():
	print(green("I'm get 110's test directory to 167"))
	get('~/test', '~/remote-test')
	print(yellow("I'm 110 test directory"))
	local('ls -l ~/test')

def deploy():
	execute(task1)
	execute(task2)


