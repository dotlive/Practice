from fabric.api import *
from fabric.colors import *
from fabric.context_managers import *

env.roledefs={'web1':['192.168.115.110'],'web2':['192.168.115.167']}
env.password='amythpcel'

@roles('web1')
def task1():
	with cd('~/test'):
		run('ls -l')

@roles('web2')
def task2():
	print(green("I'm task2"))

def deploy():
	execute(task1)
	execute(task2)
