from fabric.api import *
from fabric.context_managers import *

env.hosts=['192.168.115.110','192.168.115.167']
env.password='amythpcel'
env.exclude_hosts=['192.168.115.110']

def task():
	with cd('~/test'):
		run('ls -l')
