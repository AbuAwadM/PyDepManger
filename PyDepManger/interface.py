import subprocess

class Manger:
    def blueprint(app):
        subprocess.run(["./PyDepManger/bash/blueprint.sh", app])
        
    def java():
        app = "java"
        Manger.blueprint(app)
    
    def python():
        app = "py"
        Manger.blueprint(app)
        

    
        
    


