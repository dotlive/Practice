from fabric.api import *
from fabric.colors import *
from fabric.context_managers import *

env.hosts=['192.168.115.110','192.168.115.167']
env.password='amythpcel'
env.exclude_hosts=['192.168.115.110']

def task1():
	with cd('~/test'):
		run('ls -l')

def task2():
	print(green("I'm task2"))

def deploy():
	execute(task1)
	execute(task2)
