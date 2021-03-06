#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include <QtSql>
#include <QFileDialog>
#include <stack>

const size_t code_file_suffix_size = 7;
QString code_file_suffix[] = {"cpp","h","cxx","hpp",
                              "js",
                              "py",
                              "c"
                             };
const size_t img_file_suffix_size = 5;
QString img_file_suffix[] = {"png","jpg","icon","svg","ico"};

bool isFileType(QString suffix,QString file_suffix_array[],const size_t count)
{
    bool ret = false;
    qDebug() << sizeof (file_suffix_array);
    for(size_t i = 0; i < count;i++)
    {
        if(suffix == file_suffix_array[i])
        {
            ret = true;
            break;
        }
    }
    return ret;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadIcon();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    const QString dirName(QFileDialog::getExistingDirectory(this, "Choose a directory", m_curDir));
    if (!dirName.isEmpty()) {
        QDir d(dirName);
        //setRepository(d.absolutePath());
        m_curDir = d.absolutePath();
        qDebug() << d.absolutePath();
        getfiles(m_curDir);
    }
}

void MainWindow::on_actionClose_triggered()
{

}

void MainWindow::loadIcon()
{
    m_iconMap[ACTIONSCRIPT_TYPE] = QIcon(":rc/icon/actionscript.png");
    m_iconMap[ADVPL_PRW_TYPE] = QIcon(":rc/icon/advpl_prw.png");
    m_iconMap[ANDROID_TYPE] = QIcon(":rc/icon/android.png");
    m_iconMap[ANGULAR_RESOLVER_TYPE] = QIcon(":rc/icon/angular-resolver.png");
    m_iconMap[APIBLUEPRINT_TYPE] = QIcon(":rc/icon/apiblueprint.png");
    m_iconMap[APPLESCRIPT_TYPE] = QIcon(":rc/icon/applescript.png");
    m_iconMap[APPVEYOR_TYPE] = QIcon(":rc/icon/appveyor.png");
    m_iconMap[ASCIIDOC_TYPE] = QIcon(":rc/icon/asciidoc.png");
    m_iconMap[ASSEMBLY_TYPE] = QIcon(":rc/icon/assembly.png");
    m_iconMap[AUDIO_TYPE] = QIcon(":rc/icon/audio.png");
    m_iconMap[AUTHORS_TYPE] = QIcon(":rc/icon/authors.png");
    m_iconMap[AUTOHOTKEY_TYPE] = QIcon(":rc/icon/autohotkey.png");
    m_iconMap[AUTOIT_TYPE] = QIcon(":rc/icon/autoit.png");
    m_iconMap[AZURE_PIPELINES_TYPE] = QIcon(":rc/icon/azure-pipelines.png");
    m_iconMap[AZURE_TYPE] = QIcon(":rc/icon/azure.png");
    m_iconMap[BABEL_TYPE] = QIcon(":rc/icon/babel.png");
    m_iconMap[BALLERINA_TYPE] = QIcon(":rc/icon/ballerina.png");
    m_iconMap[BAZEL_TYPE] = QIcon(":rc/icon/bazel.png");
    m_iconMap[BITHOUND_TYPE] = QIcon(":rc/icon/bithound.png");
    m_iconMap[BLINK_TYPE] = QIcon(":rc/icon/blink.png");
    m_iconMap[BLINK_LIGHT_TYPE] = QIcon(":rc/icon/blink_light.png");
    m_iconMap[BOWER_TYPE] = QIcon(":rc/icon/bower.png");
    m_iconMap[BROWSERLIST_TYPE] = QIcon(":rc/icon/browserlist.png");
    m_iconMap[BROWSERLIST_LIGHT_TYPE] = QIcon(":rc/icon/browserlist_light.png");
    m_iconMap[BUCKLESCRIPT_TYPE] = QIcon(":rc/icon/bucklescript.png");
    m_iconMap[BUILDKITE_TYPE] = QIcon(":rc/icon/buildkite.png");
    m_iconMap[C_TYPE] = QIcon(":rc/icon/c.png");
    m_iconMap[CAKE_TYPE] = QIcon(":rc/icon/cake.png");
    m_iconMap[CERTIFICATE_TYPE] = QIcon(":rc/icon/certificate.png");
    m_iconMap[CHANGELOG_TYPE] = QIcon(":rc/icon/changelog.png");
    m_iconMap[CIRCLECI_TYPE] = QIcon(":rc/icon/circleci.png");
    m_iconMap[CIRCLECI_LIGHT_TYPE] = QIcon(":rc/icon/circleci_light.png");
    m_iconMap[CLOJURE_TYPE] = QIcon(":rc/icon/clojure.png");
    m_iconMap[CMAKE_TYPE] = QIcon(":rc/icon/cmake.png");
    m_iconMap[CODE_CLIMATE_LIGHT_TYPE] = QIcon(":rc/icon/code-climate_light.png");
    m_iconMap[CODECOV_TYPE] = QIcon(":rc/icon/codecov.png");
    m_iconMap[CODEOWNERS_TYPE] = QIcon(":rc/icon/codeowners.png");
    m_iconMap[COFFEE_TYPE] = QIcon(":rc/icon/coffee.png");
    m_iconMap[COLDFUSION_TYPE] = QIcon(":rc/icon/coldfusion.png");
    m_iconMap[CONDUCT_TYPE] = QIcon(":rc/icon/conduct.png");
    m_iconMap[CONSOLE_TYPE] = QIcon(":rc/icon/console.png");
    m_iconMap[CONTRIBUTING_TYPE] = QIcon(":rc/icon/contributing.png");
    m_iconMap[CPP_TYPE] = QIcon(":rc/icon/cpp.png");
    m_iconMap[CREDITS_TYPE] = QIcon(":rc/icon/credits.png");
    m_iconMap[CRYSTAL_LIGHT_TYPE] = QIcon(":rc/icon/crystal_light.png");
    m_iconMap[CSHARP_TYPE] = QIcon(":rc/icon/csharp.png");
    m_iconMap[CSS_MAP_TYPE] = QIcon(":rc/icon/css-map.png");
    m_iconMap[CSS_TYPE] = QIcon(":rc/icon/css.png");
    m_iconMap[CUCUMBER_TYPE] = QIcon(":rc/icon/cucumber.png");
    m_iconMap[CUDA_TYPE] = QIcon(":rc/icon/cuda.png");
    m_iconMap[D_TYPE] = QIcon(":rc/icon/d.png");
    m_iconMap[DART_TYPE] = QIcon(":rc/icon/dart.png");
    m_iconMap[DATABASE_TYPE] = QIcon(":rc/icon/database.png");
    m_iconMap[DIFF_TYPE] = QIcon(":rc/icon/diff.png");
    m_iconMap[DISC_TYPE] = QIcon(":rc/icon/disc.png");
    m_iconMap[DJANGO_TYPE] = QIcon(":rc/icon/django.png");
    m_iconMap[DOCUMENT_TYPE] = QIcon(":rc/icon/document.png");
    m_iconMap[DRONE_LIGHT_TYPE] = QIcon(":rc/icon/drone_light.png");
    m_iconMap[EDGE_TYPE] = QIcon(":rc/icon/edge.png");
    m_iconMap[EJS_TYPE] = QIcon(":rc/icon/ejs.png");
    m_iconMap[ELIXIR_TYPE] = QIcon(":rc/icon/elixir.png");
    m_iconMap[ELM_TYPE] = QIcon(":rc/icon/elm.png");
    m_iconMap[EMAIL_TYPE] = QIcon(":rc/icon/email.png");
    m_iconMap[ERLANG_TYPE] = QIcon(":rc/icon/erlang.png");
    m_iconMap[ESLINT_TYPE] = QIcon(":rc/icon/eslint.png");
    m_iconMap[EXCEL_TYPE] = QIcon(":rc/icon/excel.png");
    m_iconMap[EXE_TYPE] = QIcon(":rc/icon/exe.png");
    m_iconMap[FASTLANE_TYPE] = QIcon(":rc/icon/fastlane.png");
    m_iconMap[FAVICON_TYPE] = QIcon(":rc/icon/favicon.png");
    m_iconMap[FILE_TYPE] = QIcon(":rc/icon/file.png");
    m_iconMap[FIREBASE_TYPE] = QIcon(":rc/icon/firebase.png");
    m_iconMap[FLOW_TYPE] = QIcon(":rc/icon/flow.png");
    m_iconMap[FOLDER_ANDROID_TYPE] = QIcon(":rc/icon/folder-android.png");
    m_iconMap[FOLDER_AUDIO_TYPE] = QIcon(":rc/icon/folder-audio.png");
    m_iconMap[FOLDER_AWS_TYPE] = QIcon(":rc/icon/folder-aws.png");
    m_iconMap[FOLDER_BATCH_OPEN_TYPE] = QIcon(":rc/icon/folder-batch-open.png");
    m_iconMap[FOLDER_CI_OPEN_TYPE] = QIcon(":rc/icon/folder-ci-open.png");
    m_iconMap[FOLDER_CI_TYPE] = QIcon(":rc/icon/folder-ci.png");
    m_iconMap[FOLDER_CIRCLECI_OPEN_TYPE] = QIcon(":rc/icon/folder-circleci-open.png");
    m_iconMap[FOLDER_CIRCLECI_TYPE] = QIcon(":rc/icon/folder-circleci.png");
    m_iconMap[FOLDER_CLIENT_TYPE] = QIcon(":rc/icon/folder-client.png");
    m_iconMap[FOLDER_COMMAND_TYPE] = QIcon(":rc/icon/folder-command.png");
    m_iconMap[FOLDER_COMPONENTS_TYPE] = QIcon(":rc/icon/folder-components.png");
    m_iconMap[FOLDER_CONFIG_TYPE] = QIcon(":rc/icon/folder-config.png");
    m_iconMap[FOLDER_CUSTOM_TYPE] = QIcon(":rc/icon/folder-custom.png");
    m_iconMap[FOLDER_DOCS_TYPE] = QIcon(":rc/icon/folder-docs.png");
    m_iconMap[FOLDER_TYPE] = QIcon(":rc/icon/folder.png");
    m_iconMap[FONT_TYPE] = QIcon(":rc/icon/font.png");
    m_iconMap[FORTRAN_TYPE] = QIcon(":rc/icon/fortran.png");
    m_iconMap[FOXPRO_TYPE] = QIcon(":rc/icon/foxpro.png");
    m_iconMap[FSHARP_TYPE] = QIcon(":rc/icon/fsharp.png");
    m_iconMap[FUSEBOX_TYPE] = QIcon(":rc/icon/fusebox.png");
    m_iconMap[GATSBY_TYPE] = QIcon(":rc/icon/gatsby.png");
    m_iconMap[GCP_TYPE] = QIcon(":rc/icon/gcp.png");
    m_iconMap[GEMFILE_TYPE] = QIcon(":rc/icon/gemfile.png");
    m_iconMap[GIT_TYPE] = QIcon(":rc/icon/git.png");
    m_iconMap[GITLAB_TYPE] = QIcon(":rc/icon/gitlab.png");
    m_iconMap[GITPOD_TYPE] = QIcon(":rc/icon/gitpod.png");
    m_iconMap[GO_MOD_TYPE] = QIcon(":rc/icon/go-mod.png");
    m_iconMap[GO_TYPE] = QIcon(":rc/icon/go.png");
    m_iconMap[GODOT_ASSETS_TYPE] = QIcon(":rc/icon/godot-assets.png");
    m_iconMap[GODOT_TYPE] = QIcon(":rc/icon/godot.png");
    m_iconMap[GO_GOPHER_TYPE] = QIcon(":rc/icon/go_gopher.png");
    m_iconMap[GRADLE_TYPE] = QIcon(":rc/icon/gradle.png");
    m_iconMap[GRAPHCOOL_TYPE] = QIcon(":rc/icon/graphcool.png");
    m_iconMap[GRAPHQL_TYPE] = QIcon(":rc/icon/graphql.png");
    m_iconMap[GROOVY_TYPE] = QIcon(":rc/icon/groovy.png");
    m_iconMap[GRUNT_TYPE] = QIcon(":rc/icon/grunt.png");
    m_iconMap[GULP_TYPE] = QIcon(":rc/icon/gulp.png");
    m_iconMap[H_TYPE] = QIcon(":rc/icon/h.png");
    m_iconMap[HACK_TYPE] = QIcon(":rc/icon/hack.png");
    m_iconMap[HAML_TYPE] = QIcon(":rc/icon/haml.png");
    m_iconMap[HANDLEBARS_TYPE] = QIcon(":rc/icon/handlebars.png");
    m_iconMap[HASKELL_TYPE] = QIcon(":rc/icon/haskell.png");
    m_iconMap[HAXE_TYPE] = QIcon(":rc/icon/haxe.png");
    m_iconMap[HCL_LIGHT_TYPE] = QIcon(":rc/icon/hcl_light.png");
    m_iconMap[HELM_TYPE] = QIcon(":rc/icon/helm.png");
    m_iconMap[HEROKU_TYPE] = QIcon(":rc/icon/heroku.png");
    m_iconMap[HPP_TYPE] = QIcon(":rc/icon/hpp.png");
    m_iconMap[HTML_TYPE] = QIcon(":rc/icon/html.png");
    m_iconMap[HTTP_TYPE] = QIcon(":rc/icon/http.png");
    m_iconMap[HUSKY_TYPE] = QIcon(":rc/icon/husky.png");
    m_iconMap[IMAGE_TYPE] = QIcon(":rc/icon/image.png");
    m_iconMap[IN_TYPE] = QIcon(":rc/icon/in.png");
    m_iconMap[IONIC_TYPE] = QIcon(":rc/icon/ionic.png");
    m_iconMap[ISTANBUL_TYPE] = QIcon(":rc/icon/istanbul.png");
    m_iconMap[JAVA_TYPE] = QIcon(":rc/icon/java.png");
    m_iconMap[JAVASCRIPT_MAP_TYPE] = QIcon(":rc/icon/javascript-map.png");
    m_iconMap[JAVASCRIPT_TYPE] = QIcon(":rc/icon/javascript.png");
    m_iconMap[JEST_TYPE] = QIcon(":rc/icon/jest.png");
    m_iconMap[JINJA_LIGHT_TYPE] = QIcon(":rc/icon/jinja_light.png");
    m_iconMap[JSON_TYPE] = QIcon(":rc/icon/json.png");
    m_iconMap[JULIA_TYPE] = QIcon(":rc/icon/julia.png");
    m_iconMap[JUPYTER_TYPE] = QIcon(":rc/icon/jupyter.png");
    m_iconMap[KARMA_TYPE] = QIcon(":rc/icon/karma.png");
    m_iconMap[KEY_TYPE] = QIcon(":rc/icon/key.png");
    m_iconMap[KIVY_TYPE] = QIcon(":rc/icon/kivy.png");
    m_iconMap[KL_TYPE] = QIcon(":rc/icon/kl.png");
    m_iconMap[LARAVEL_TYPE] = QIcon(":rc/icon/laravel.png");
    m_iconMap[LESS_TYPE] = QIcon(":rc/icon/less.png");
    m_iconMap[LIB_TYPE] = QIcon(":rc/icon/lib.png");
    m_iconMap[LIQUID_TYPE] = QIcon(":rc/icon/liquid.png");
    m_iconMap[LIVESCRIPT_TYPE] = QIcon(":rc/icon/livescript.png");
    m_iconMap[LOCK_TYPE] = QIcon(":rc/icon/lock.png");
    m_iconMap[LOG_TYPE] = QIcon(":rc/icon/log.png");
    m_iconMap[LUA_TYPE] = QIcon(":rc/icon/lua.png");
    m_iconMap[MAKEFILE_TYPE] = QIcon(":rc/icon/makefile.png");
    m_iconMap[MARKDOWN_TYPE] = QIcon(":rc/icon/markdown.png");
    m_iconMap[MARKOJS_TYPE] = QIcon(":rc/icon/markojs.png");
    m_iconMap[MATHEMATICA_TYPE] = QIcon(":rc/icon/mathematica.png");
    m_iconMap[MATLAB_TYPE] = QIcon(":rc/icon/matlab.png");
    m_iconMap[MDX_TYPE] = QIcon(":rc/icon/mdx.png");
    m_iconMap[MERLIN_TYPE] = QIcon(":rc/icon/merlin.png");
    m_iconMap[MINT_TYPE] = QIcon(":rc/icon/mint.png");
    m_iconMap[MJML_TYPE] = QIcon(":rc/icon/mjml.png");
    m_iconMap[MOCHA_TYPE] = QIcon(":rc/icon/mocha.png");
    m_iconMap[MOONSCRIPT_TYPE] = QIcon(":rc/icon/moonscript.png");
    m_iconMap[MXML_TYPE] = QIcon(":rc/icon/mxml.png");
    m_iconMap[NEST_CONTROLLER_TYPE] = QIcon(":rc/icon/nest-controller.png");
    m_iconMap[NEST_SERVICE_TYPE] = QIcon(":rc/icon/nest-service.png");
    m_iconMap[NETLIFY_TYPE] = QIcon(":rc/icon/netlify.png");
    m_iconMap[NGRX_ACTIONS_TYPE] = QIcon(":rc/icon/ngrx-actions.png");
    m_iconMap[NIM_TYPE] = QIcon(":rc/icon/nim.png");
    m_iconMap[NIX_TYPE] = QIcon(":rc/icon/nix.png");
    m_iconMap[NODEJS_TYPE] = QIcon(":rc/icon/nodejs.png");
    m_iconMap[NPM_TYPE] = QIcon(":rc/icon/npm.png");
    m_iconMap[NUNJUCKS_TYPE] = QIcon(":rc/icon/nunjucks.png");
    m_iconMap[NUXT_TYPE] = QIcon(":rc/icon/nuxt.png");
    m_iconMap[OUTLOOK_TYPE] = QIcon(":rc/icon/outlook.png");
    m_iconMap[PDF_TYPE] = QIcon(":rc/icon/pdf.png");
    m_iconMap[PERCY_TYPE] = QIcon(":rc/icon/percy.png");
    m_iconMap[PERL_TYPE] = QIcon(":rc/icon/perl.png");
    m_iconMap[PHP_TYPE] = QIcon(":rc/icon/php.png");
    m_iconMap[PHP_ELEPHANT_TYPE] = QIcon(":rc/icon/php_elephant.png");
    m_iconMap[POSTCSS_TYPE] = QIcon(":rc/icon/postcss.png");
    m_iconMap[POWERPOINT_TYPE] = QIcon(":rc/icon/powerpoint.png");
    m_iconMap[POWERSHELL_TYPE] = QIcon(":rc/icon/powershell.png");
    m_iconMap[PRISMA_TYPE] = QIcon(":rc/icon/prisma.png");
    m_iconMap[PROCESSING_LIGHT_TYPE] = QIcon(":rc/icon/processing_light.png");
    m_iconMap[PROLOG_TYPE] = QIcon(":rc/icon/prolog.png");
    m_iconMap[PUG_TYPE] = QIcon(":rc/icon/pug.png");
    m_iconMap[PUPPET_TYPE] = QIcon(":rc/icon/puppet.png");
    m_iconMap[PURESCRIPT_TYPE] = QIcon(":rc/icon/purescript.png");
    m_iconMap[PYTHON_MISC_TYPE] = QIcon(":rc/icon/python-misc.png");
    m_iconMap[PYTHON_TYPE] = QIcon(":rc/icon/python.png");
    m_iconMap[QSHARP_TYPE] = QIcon(":rc/icon/qsharp.png");
    m_iconMap[R_TYPE] = QIcon(":rc/icon/r.png");
    m_iconMap[RACKET_TYPE] = QIcon(":rc/icon/racket.png");
    m_iconMap[RAML_TYPE] = QIcon(":rc/icon/raml.png");
    m_iconMap[RAZOR_TYPE] = QIcon(":rc/icon/razor.png");
    m_iconMap[REACT_TYPE] = QIcon(":rc/icon/react.png");
    m_iconMap[REACT_TS_TYPE] = QIcon(":rc/icon/react_ts.png");
    m_iconMap[README_TYPE] = QIcon(":rc/icon/readme.png");
    m_iconMap[REASON_TYPE] = QIcon(":rc/icon/reason.png");
    m_iconMap[RED_TYPE] = QIcon(":rc/icon/red.png");
    m_iconMap[REDUX_ACTION_TYPE] = QIcon(":rc/icon/redux-action.png");
    m_iconMap[REDUX_REDUCER_TYPE] = QIcon(":rc/icon/redux-reducer.png");
    m_iconMap[REDUX_STORE_TYPE] = QIcon(":rc/icon/redux-store.png");
    m_iconMap[RESTQL_TYPE] = QIcon(":rc/icon/restql.png");
    m_iconMap[RIOT_TYPE] = QIcon(":rc/icon/riot.png");
    m_iconMap[ROBOT_TYPE] = QIcon(":rc/icon/robot.png");
    m_iconMap[ROUTING_TYPE] = QIcon(":rc/icon/routing.png");
    m_iconMap[RUBY_TYPE] = QIcon(":rc/icon/ruby.png");
    m_iconMap[RUST_TYPE] = QIcon(":rc/icon/rust.png");
    m_iconMap[SAN_TYPE] = QIcon(":rc/icon/san.png");
    m_iconMap[SASS_TYPE] = QIcon(":rc/icon/sass.png");
    m_iconMap[SBT_TYPE] = QIcon(":rc/icon/sbt.png");
    m_iconMap[SCALA_TYPE] = QIcon(":rc/icon/scala.png");
    m_iconMap[SCHEME_TYPE] = QIcon(":rc/icon/scheme.png");
    m_iconMap[SEMANTIC_RELEASE_TYPE] = QIcon(":rc/icon/semantic-release.png");
    m_iconMap[SEMANTIC_RELEASE_LIGHT_TYPE] = QIcon(":rc/icon/semantic-release_light.png");
    m_iconMap[SEQUELIZE_TYPE] = QIcon(":rc/icon/sequelize.png");
    m_iconMap[SETTINGS_TYPE] = QIcon(":rc/icon/settings.png");
    m_iconMap[SHADERLAB_TYPE] = QIcon(":rc/icon/shaderlab.png");
    m_iconMap[SILVERSTRIPE_TYPE] = QIcon(":rc/icon/silverstripe.png");
    m_iconMap[SLIM_TYPE] = QIcon(":rc/icon/slim.png");
    m_iconMap[SMARTY_TYPE] = QIcon(":rc/icon/smarty.png");
    m_iconMap[SNYK_TYPE] = QIcon(":rc/icon/snyk.png");
    m_iconMap[SOLIDITY_TYPE] = QIcon(":rc/icon/solidity.png");
    m_iconMap[STENCIL_TYPE] = QIcon(":rc/icon/stencil.png");
    m_iconMap[STENCIL_LIGHT_TYPE] = QIcon(":rc/icon/stencil_light.png");
    m_iconMap[STORYBOOK_TYPE] = QIcon(":rc/icon/storybook.png");
    m_iconMap[STYLELINT_TYPE] = QIcon(":rc/icon/stylelint.png");
    m_iconMap[STYLELINT_LIGHT_TYPE] = QIcon(":rc/icon/stylelint_light.png");
    m_iconMap[STYLUS_TYPE] = QIcon(":rc/icon/stylus.png");
    m_iconMap[SUBLIME_TYPE] = QIcon(":rc/icon/sublime.png");
    m_iconMap[SVELTE_TYPE] = QIcon(":rc/icon/svelte.png");
    m_iconMap[SVG_TYPE] = QIcon(":rc/icon/svg.png");
    m_iconMap[SWIFT_TYPE] = QIcon(":rc/icon/swift.png");
    m_iconMap[TABLE_TYPE] = QIcon(":rc/icon/table.png");
    m_iconMap[TAILWINDCSS_TYPE] = QIcon(":rc/icon/tailwindcss.png");
    m_iconMap[TERRAFORM_TYPE] = QIcon(":rc/icon/terraform.png");
    m_iconMap[TEST_JS_TYPE] = QIcon(":rc/icon/test-js.png");
    m_iconMap[TEST_JSX_TYPE] = QIcon(":rc/icon/test-jsx.png");
    m_iconMap[TEST_TS_TYPE] = QIcon(":rc/icon/test-ts.png");
    m_iconMap[TEX_TYPE] = QIcon(":rc/icon/tex.png");
    m_iconMap[TODO_TYPE] = QIcon(":rc/icon/todo.png");
    m_iconMap[TRAVIS_TYPE] = QIcon(":rc/icon/travis.png");
    m_iconMap[TUNE_TYPE] = QIcon(":rc/icon/tune.png");
    m_iconMap[TWIG_TYPE] = QIcon(":rc/icon/twig.png");
    m_iconMap[TYPESCRIPT_DEF_TYPE] = QIcon(":rc/icon/typescript-def.png");
    m_iconMap[TYPESCRIPT_TYPE] = QIcon(":rc/icon/typescript.png");
    m_iconMap[URL_TYPE] = QIcon(":rc/icon/url.png");
    m_iconMap[VAGRANT_TYPE] = QIcon(":rc/icon/vagrant.png");
    m_iconMap[VELOCITY_TYPE] = QIcon(":rc/icon/velocity.png");
    m_iconMap[VERILOG_TYPE] = QIcon(":rc/icon/verilog.png");
    m_iconMap[VIDEO_TYPE] = QIcon(":rc/icon/video.png");
    m_iconMap[VIM_TYPE] = QIcon(":rc/icon/vim.png");
    m_iconMap[VIRTUAL_TYPE] = QIcon(":rc/icon/virtual.png");
    m_iconMap[VISUALSTUDIO_TYPE] = QIcon(":rc/icon/visualstudio.png");
    m_iconMap[VSCODE_TYPE] = QIcon(":rc/icon/vscode.png");
    m_iconMap[VUE_CONFIG_TYPE] = QIcon(":rc/icon/vue-config.png");
    m_iconMap[VUE_TYPE] = QIcon(":rc/icon/vue.png");
    m_iconMap[VUEX_STORE_TYPE] = QIcon(":rc/icon/vuex-store.png");
    m_iconMap[WAKATIME_TYPE] = QIcon(":rc/icon/wakatime.png");
    m_iconMap[WAKATIME_LIGHT_TYPE] = QIcon(":rc/icon/wakatime_light.png");
    m_iconMap[WALLABY_TYPE] = QIcon(":rc/icon/wallaby.png");
    m_iconMap[WATCHMAN_TYPE] = QIcon(":rc/icon/watchman.png");
    m_iconMap[WEBASSEMBLY_TYPE] = QIcon(":rc/icon/webassembly.png");
    m_iconMap[WEBHINT_TYPE] = QIcon(":rc/icon/webhint.png");
    m_iconMap[WEBPACK_TYPE] = QIcon(":rc/icon/webpack.png");
    m_iconMap[WEPY_TYPE] = QIcon(":rc/icon/wepy.png");
    m_iconMap[WOLFRAMLANGUAGE_TYPE] = QIcon(":rc/icon/wolframlanguage.png");
    m_iconMap[WORD_TYPE] = QIcon(":rc/icon/word.png");
    m_iconMap[WORD_1_TYPE] = QIcon(":rc/icon/word_1.png");
    m_iconMap[XAML_TYPE] = QIcon(":rc/icon/xaml.png");
    m_iconMap[XML_TYPE] = QIcon(":rc/icon/xml.png");
    m_iconMap[YAML_TYPE] = QIcon(":rc/icon/yaml.png");
    m_iconMap[YANG_TYPE] = QIcon(":rc/icon/yang.png");
    m_iconMap[YARN_TYPE] = QIcon(":rc/icon/yarn.png");
    m_iconMap[YELLOWFOLDER_TYPE] = QIcon(":rc/icon/yellowFolder.png");
    m_iconMap[YELLOWFOLDER_1_TYPE] = QIcon(":rc/icon/yellowFolder_1.png");
    m_iconMap[ZIG_TYPE] = QIcon(":rc/icon/zig.png");
    m_iconMap[ZIP_TYPE] = QIcon(":rc/icon/zip.png");
}

QStringList MainWindow::getfiles(const QString &dir_path)
{
    ui->treeWidget->clear();
    ui->treeWidget->update();
    QStringList get_files;
    QDir dir(dir_path);
    if(!dir.exists())
    {
        qDebug() << "it is not true dir_path";
    }
    QIcon icon_file = m_iconMap[YELLOWFOLDER_TYPE];
    std::stack<std::pair<QString,QTreeWidgetItem *>> stack;
    QTreeWidgetItem *cur = new QTreeWidgetItem(ui->treeWidget);
    cur->setIcon(0,icon_file);
    cur->setText(0,dir.dirName());
    ui->treeWidget->setHeaderHidden(true);
    ui->treeWidget->setAnimated(true);
    ui->treeWidget->addTopLevelItem(cur);
    stack.push(std::make_pair(dir.absolutePath(),cur));
    while(!stack.empty())
    {
        auto pair = stack.top();
        stack.pop();
        QDir curDir(pair.first);
        auto pCurItem = pair.second;
        auto infoList = curDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
        qDebug()<< "root " <<pair.first;
        for(int i = 0; i < infoList.size(); i++)
        {
            QFileInfo subdir(infoList.at(i));
            if(subdir.absoluteFilePath() == pair.first)
            {
                qDebug()<< "continue" <<subdir.absoluteFilePath();
                continue;
            }
            qDebug()<<subdir.absoluteFilePath();
            QTreeWidgetItem *subItem = new QTreeWidgetItem(pCurItem);
            if(subdir.isDir())
            {
                subItem->setIcon(0,icon_file);
                qDebug()<< "push" <<subdir.absoluteFilePath();
                stack.push(std::make_pair(subdir.absoluteFilePath(),subItem));
            }
            else
            {
                auto suffix = subdir.suffix();
                if(isFileType(suffix,code_file_suffix,code_file_suffix_size))
                {
                    subItem->setIcon(0,m_iconMap[CPP_TYPE]);
                }
                else if(isFileType(suffix,img_file_suffix,img_file_suffix_size))
                {
                    subItem->setIcon(0,m_iconMap[IMAGE_TYPE]);
                }
                else
                {
                    subItem->setIcon(0,m_iconMap[FILE_TYPE]);
                }
            }
            subItem->setText(0,subdir.fileName());
            pCurItem->insertChild(i,subItem);

        }
    }
    ui->treeWidget->update();
    return get_files;
}
