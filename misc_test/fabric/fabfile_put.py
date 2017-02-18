from fabric.api import *
from fabric.colors import *
from fabric.context_managers import *

env.hosts=['192.168.115.110']
env.password='amythpcel'

def task1():
	print(green("I'm 167 test file"))
	with cd('~/'):
		run('ls -l')

def task2():
	print(green("I'm put 167' test file to 110' home directory"))
	put('~/test.txt','~/mpb-test.txt')
	print(yellow("I'm 167's test file"))
	with cd('~/'):
		run('ls -l')

def deploy():
	execute(task1)
	execute(task2)
