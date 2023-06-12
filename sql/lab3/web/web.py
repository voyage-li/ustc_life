from flask import Flask, render_template, redirect, request, session, flash
from datetime import timedelta
import pymysql

app = Flask(__name__)
app.secret_key = "Hello world"


def usesql(sentence):
    db = pymysql.connect(host='localhost', user='root',
                         passwd='voyage', database='lab3')
    cursor = db.cursor()
    print(sentence)
    cursor.execute(sentence)
    tmp = cursor.fetchall()
    db.commit()
    cursor.close()
    db.close()
    return tmp


def updatpost(num):
    teacherlist = usesql('select * from teacher')
    teacherdata = {}
    for item in teacherlist:
        teacherdata[item[0]] = item[1]
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
    if num == 0:
        return render_template('paper.html', data_list=anslist)
    else:
        return render_template('paper.html', data_list=anslist, form_data=request.form)


def updateproject(num):
    teacherlist = usesql('select * from teacher')
    teacherdata = {}
    for item in teacherlist:
        teacherdata[item[0]] = item[1]
    prolist = usesql('select * from Project')
    prodata = {}
    for item in prolist:
        prodata[item[0]] = item[1]
    anslist = []
    havelist = usesql('select * from HaveProject')
    for item in havelist:
        anslist.append({
            'teid': item[0],
            'teacher': teacherdata[item[0]],
            'proid': item[1],
            'proname': prodata[item[1]],
            'rank': item[2],
            'cost': item[3]
        })
    if num == 0:
        return render_template('project.html', data_list=anslist)
    else:
        return render_template('project.html', data_list=anslist, form_data=request.form)


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
            return updatpost(0)
    if not request.form:
        session.pop('account')
        print('log out')
        return redirect("/login/")
    try:
        techid = request.form.get('techid')
        papid = int(request.form.get('papid'))
        papname = request.form.get('papname')
        papsource = request.form.get('papsource')
        papyear = str(request.form.get('papyear'))+'-0-0'
        paptype = int(request.form.get('paptype'))
        paplevel = int(request.form.get('paplevel'))
        rank = int(request.form.get('rank'))
        isau = True if request.form.get('isau') == '是' else False
    except:
        flash('输入错误!')
        return updatpost(1)
    if not usesql(f"select * from teacher where TeacherNum = \'{techid}\'"):
        flash('教师不存在！')
    elif usesql(f"select * from Paper where PaperID = {papid}"):
        if usesql(f"select * from PostPaper where PaperID = {papid} and IsAuthor = True") and isau == True:
            flash('论文不能有两个通讯作者！')
        elif usesql(f"select * from PostPaper where PaperID = {papid} and PostRank = {rank}"):
            flash('论文的排名不能重复！')
        elif usesql(f"select * from PostPaper where PaperID = {papid} and TeacherNum =\'{techid}\'"):
            flash('不能重复添加！')
        else:
            usesql(
                f"insert into PostPaper value(\'{techid}\',{papid},{rank},{isau})")
            flash('添加成功！')
            return updatpost(0)
    else:
        usesql(
            f"insert into Paper value({papid},\'{papname}\',\'{papsource}\',\'{papyear}\',{paptype},{paplevel})")
        usesql(
            f"insert into PostPaper value(\'{techid}\',{papid},{rank},{isau})")
        flash('添加成功！')
        return updatpost(0)
    return updatpost(1)


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
    try:
        print(request.form)
        for i in request.form:
            if request.form.get(i) == '':
                flash('输入不能为空')
                return updateproject(0)
        proid = request.form.get('proid')
        proname = request.form.get('proname')
        profrom = request.form.get('profrom')
        procost = float(request.form.get('procost'))
        beginyear = str(request.form.get('beginyear'))+'-0-0'
        endyear = str(request.form.get('endyear'))+'-0-0'
        protype = int(request.form.get('protype'))
        num = int(request.form.get('total'))
        teid = []
        terank = []
        tecost = []
        for i in range(num):
            teid.append(request.form.get('teid'+str(i)))
            terank.append(int(request.form.get('terank'+str(i))))
            tecost.append(float(request.form.get('tecost'+str(i))))
    except:
        flash('输入错误')
        return updateproject(1)
    if procost != sum(tecost):
        flash('经费统计出现错误！')
    elif len(terank) != len(set(terank)):
        flash('排名出现重复！')
    else:
        if usesql(f"select * from Project where ProjectID = \'{proid}\'"):
            flash(f"项目编号已经存在")
            return updateproject(1)
        usesql(
            f"insert into Project value(\'{proid}\',\'{proname}\',\'{profrom}\',{protype},{procost},{beginyear},{endyear})")
        for i in range(num):
            if not usesql(f"select TeacherName from teacher where TeacherNum = \'{teid[i]}\'"):
                flash(f"编号为{teid[i]}的教师不存在")
                return updateproject(1)
        for i in range(num):
            usesql(
                f"insert into HaveProject value(\'{teid[i]}\',\'{proid}\',{terank[i]},{tecost[i]})")
        return updateproject(0)
    return updateproject(1)


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
