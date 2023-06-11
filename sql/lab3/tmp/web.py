from flask import Flask, render_template, redirect, request, session, flash
from datetime import timedelta
import pymysql

app = Flask(__name__)
app.secret_key = "Hello world"


def usesql(sentence):
    db = pymysql.connect(host='localhost', user='root',
                         passwd='voyage', database='lab3')
    cursor = db.cursor()
    cursor.execute(sentence)
    print(sentence)
    tmp = cursor.fetchall()
    db.commit()
    cursor.close()
    db.close()
    return tmp


def updatpost():
    teacherlist = usesql('select * from teacher')
    teacherdata = {}
    for item in teacherlist:
        teacherdata[item[0]] = item[1]
    print(teacherdata)
    paperlist = usesql('select * from Paper')
    paperdata = {}
    for item in paperlist:
        paperdata[item[0]] = item[1]
    postlist = usesql('select * from PostPaper')
    anslist = []
    for item in postlist:
        anslist.append({'teid': item[0],
                        'teacher': teacherdata[item[0]],
                        'paid': item[1],
                        'paname': paperdata[item[1]],
                        'rank': item[2],
                        'isau': '是' if item[3] == True else '否'
                        })
    return render_template('paper.html', data_list=anslist)


@app.route("/login/", methods=['GET', 'POST'])
def login():
    if session.get('account'):
        return redirect("/")
    if request.method == 'GET':
        return render_template('login.html')
    acceptid = request.form.get('account')
    acceptpwd = request.form.get('pwd')
    print(acceptid, acceptpwd)
    if acceptid == 'lyh_0921@mail.ustc.edu.cn' and acceptpwd == '123456':
        session['account'] = acceptid
        session.permanent = True
        app.config['PERMANENT_SESSION_LIFETIME'] = timedelta(hours=1)
        return redirect("/")
    else:
        flash('用户名或密码错误!')
        return render_template('login.html')


@app.route("/", methods=['GET', 'POST'])
def index():
    if request.method == 'GET':
        user_info = session.get('account')
        print(user_info)
        if not user_info:
            return redirect("/login/")
        else:
            return render_template("base.html")
    if not request.form:
        session.pop('account')
        print('log out')
        return redirect("/login/")


@app.route("/paper/", methods=['GET', 'POST'])
def paper():
    if request.method == 'GET':
        user_info = session.get('account')
        print(user_info)
        if not user_info:
            return redirect("/login/")
        else:
            return updatpost()
    if not request.form:
        session.pop('account')
        print('log out')
        return redirect("/login/")
    techid = request.form.get('techid')
    papid = int(request.form.get('papid'))
    papname = request.form.get('papname')
    papsource = request.form.get('papsource')
    papyear = str(request.form.get('papyear'))+'-0-0'
    paptype = int(request.form.get('paptype'))
    paplevel = int(request.form.get('paplevel'))
    rank = int(request.form.get('rank'))
    isau = True if request.form.get('isau') == '是' else False
    sql = f"call inpaper({papid},\'{papname}\',\'{papsource}\',\'{papyear}\',{paptype},{paplevel},@tmp)"
    usesql(sql)
    sql = f"call addpaper(\'{techid}\',{papid},{rank},{isau},@tmp)"
    usesql(sql)

    return updatpost()


@app.route("/project/", methods=['GET', 'POST'])
def project():
    if request.method == 'GET':
        user_info = session.get('account')
        print(user_info)
        if not user_info:
            return redirect("/login/")
        else:
            return render_template('project.html')
    if not request.form:
        session.pop('account')
        print('log out')
        return redirect("/login/")


@app.route("/course/", methods=['GET', 'POST'])
def course():
    if request.method == 'GET':
        user_info = session.get('account')
        print(user_info)
        if not user_info:
            return redirect("/login/")
        else:
            return render_template('course.html')
    if not request.form:
        session.pop('account')
        print('log out')
        return redirect("/login/")


@app.route("/search/", methods=['GET', 'POST'])
def search():
    if request.method == 'GET':
        user_info = session.get('account')
        print(user_info)
        if not user_info:
            return redirect("/login/")
        else:
            return render_template('search.html')
    if not request.form:
        session.pop('account')
        print('log out')
        return redirect("/login/")


if __name__ == "__main__":
    app.run(debug=True)
